#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e5;
ll n,h;
ll arr[MAXN];
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
  vector <ll> a(n+1);
  for(int i=0;i<n;i++){
    ll x;
    cin >> x;
    a[x] = i;
  }
  vector <ll> ord(n+1);
  for(int i=1;i<=n;i++){
    if(i%2==1) ord[i] = (i/2)+1;
    else ord[i] = n+1-(i/2);
  }
  vector <ll> ansv;
  for(int i=n;i>=1;i--){
    ll cur = a[ord[i]];
    ll ans;
    if(i%2==1){
      ans = cal(0,cur,1,0,h-1);
    }
    else{
      ans = cal(cur,n-1,1,0,h-1);
    }
    update(cur,1);
    ansv.push_back(ans);
  }
  for(int i=n-1;i>=0;i--) cout << ansv[i] << endl;
}