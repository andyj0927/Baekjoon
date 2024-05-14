#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 8e5;
const ll MOD = 1000000007;
ll n,h;
ll arr[MAXN] , cntarr[MAXN];
void update(ll i){
  i+=h;
  arr[i]+=(i-h);
  cntarr[i]+=1;
  while(i>1){
    i/=2;
    arr[i]=arr[i*2]+arr[i*2+1];
    cntarr[i]=cntarr[i*2]+cntarr[i*2+1];
  }
}
ll cnt(ll l, ll r, ll nodenum, ll nodel, ll noder){
  if(l>noder || nodel>r) return 0;
  if(l<=nodel && noder<=r) return cntarr[nodenum];
  ll mid = (nodel+noder)/2;
  return cnt(l,r,nodenum*2,nodel,mid)+cnt(l,r,nodenum*2+1,mid+1,noder);
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
  h = 1 << ((int)ceil(log2(200000)));
  vector <ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  ll ans=1;
  for(int i=0;i<n;i++){
    ll tot = cnt(0,a[i],1,0,h-1)*a[i]-cal(0,a[i],1,0,h-1);
    tot%=MOD;
    tot+= cal(a[i]+1,200000,1,0,h-1) - cnt(a[i]+1,200000,1,0,h-1)*a[i];
    tot%=MOD;
    if(i!=0 )ans*=tot;
    ans%=MOD;
    update(a[i]);
  }
  cout << ans;
}