#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
ll n,h;
ll arr[MAXN];
pll a[1000005];
bool compare(const pll &x, const pll &y){
  if(x.first==y.first) return x.second>y.second;
  return x.first < y.first;
}
void update(ll i , ll val){
  i+=h;
  arr[i]=val;
  while(i>1){
    i/=2;
    arr[i] = max(arr[i*2],arr[i*2+1]);
  }
}
ll mx(ll l , ll r, ll nodenum , ll nodel, ll noder){
  if(nodel>r || noder<l) return 0;
  if(l <= nodel && noder <= r) return arr[nodenum];
  ll mid = (nodel+noder)/2;
  return max(mx(l,r,nodenum*2,nodel,mid),mx(l,r,nodenum*2+1,mid+1,noder));
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  h = 1 << ((int)ceil(log2(n)));
  for(int i=0;i<n;i++){
    cin >> a[i].fi;
    a[i].se = i;
  }
  sort(a,a+n,compare);
  for(int i=0;i<n;i++){
    ll cur = a[i].second;
    ll ncur =mx(0,cur,1,0,h-1);
    update(cur,ncur+1);
  }
  cout << n-arr[1];
}  