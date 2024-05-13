#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
const ll INF  = 1000000001;
ll n,m,h;
ll big[MAXN],small[MAXN];
pll cal(ll l, ll r, ll nodenum , ll nodel, ll noder){
  if(nodel> r || noder <l) return {INF,0};
  if(l <= nodel && noder <= r) return {small[nodenum],big[nodenum]};
  ll mid = (nodel+noder)/2;
  pll le = cal(l,r,nodenum*2,nodel,mid);
  pll ri = cal(l,r,nodenum*2+1,mid+1,noder);
  return {min(le.first,ri.first),max(le.second,ri.second)};
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  h = 1 << ((int)ceil(log2(n)));
  for(int i=h;i<n+h;i++) {cin >> small[i]; big[i] = small[i];}
  for(int i=n+h;i<2*h;i++) {big[i] = 0; small[i]=INF;}
  for(int i=h-1;i>0;i--){
    small[i] = min(small[i*2],small[i*2+1]);
    big[i] = max(big[i*2],big[i*2+1]); 
  }
  for(int i=0;i<m;i++){
    ll a,b;
    cin >> a >> b;
    pll ans =cal(a-1,b-1,1,0,h-1);
    cout << ans.fi << " " << ans.se << endl;
  }
}  