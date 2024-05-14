#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6, INF = 1e7;
ll t,n,k,h;
ll arr[MAXN];
void update(ll i, ll val){
  i+=h;
  arr[i]+=val;
  while(i>1){
    i/=2;
    arr[i] = arr[i*2]+arr[i*2+1];
  }
}
ll cal(ll l , ll r, ll nodenum ,ll nodel, ll noder){
  if(nodel >r || noder < l) return 0;
  if(l <= nodel && noder <= r) return arr[nodenum];
  ll mid = (nodel + noder)/2;
  return cal(l,r,nodenum*2,nodel,mid)+cal(l,r,nodenum*2+1,mid+1,noder);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  h = 1 << ((int)ceil(log2(1000000)));
  while(n--){
    ll a,b,c;
    cin >> a;
    if(a==1){
      ll low = 0 , high = 1000000;
      cin >> b;
      ll taste=0;
      while(low<=high){
        ll mid = (low+high)/2;
        ll ans = cal(0,mid,1,0,h-1);
        if(ans>= b){
          taste = mid;
          high = mid-1;
        }
        else{
          low = mid+1;
        }
      }
      cout << taste+1 << endl;
      update(taste,-1);
    }
    else{
      cin >> b >> c;
      update(b-1,c);
    }
  }
}