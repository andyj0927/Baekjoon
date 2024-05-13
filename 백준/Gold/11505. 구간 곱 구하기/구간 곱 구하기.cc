#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
const ll mod = 1000000007;
ll n,m,k,h;
ll arr[MAXN];
void update(ll i ,ll val){
  i+=h;
  arr[i] = val;
  while(i>1){
    i/=2;
    arr[i] = arr[i*2]*arr[i*2+1];
    arr[i]%=mod;
  }
}
ll mul(ll l, ll r, ll nodenum , ll nodel, ll noder){
  if(nodel> r || noder <l) return 1;
  if(l <= nodel && noder <= r) return arr[nodenum];
  ll mid = (nodel+noder)/2;
  return mul(l,r,nodenum*2,nodel,mid) * mul(l,r,nodenum*2+1,mid+1,noder) % mod;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  h = 1 << ((int)ceil(log2(n)));
  for(int i=h;i<n+h;i++) cin >> arr[i];
  for(int i=n+h;i<2*h;i++) arr[i] = 1;
  for(int i=h-1;i>0;i--) {arr[i] = arr[i*2]*arr[i*2+1]; arr[i]%=mod;}
  for(int i=0;i<m+k;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    if(a==1){
      update(b-1,c);
    }
    else{
      cout << mul(b-1,c-1,1,0,h-1) << endl;
    }
  }
}  