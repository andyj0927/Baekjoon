#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 2e6;
ll n,h;
ll arr[MAXN];
bool compare(const pll &x, const pll &y){
  if(x.first==y.first) return x.second>y.second;
  return x.first > y.first;
}
void update(ll i, ll val){
  i+=h;
  arr[i] = val;
  while(i>1){
    i/=2;
    arr[i]=arr[i*2]+arr[i*2+1];
  }
}
ll cal(ll l, ll r, ll nodenum, ll nodel, ll noder){
  if(l>noder || nodel>r) return 0;
  if(l<=nodel && noder<=r) return arr[nodenum];
  ll mid = (nodel+noder)/2;
  return cal(l,r,nodenum*2,nodel,mid)+cal(l,r,nodenum*2+1,mid+1,noder);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  h = 1 << ((int)ceil(log2(n)));
  vector <pll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i].fi;
    a[i].se = i;
  }
  ll ans = 0;
  sort(a.begin(),a.end(),compare);
  for(int i=0;i<n;i++){
    ll cur = a[i].se;
    ll mx = cal(0,cur,1,0,h-1);
    update(cur,1);
    ans+= mx;
  }
  cout << ans;
}