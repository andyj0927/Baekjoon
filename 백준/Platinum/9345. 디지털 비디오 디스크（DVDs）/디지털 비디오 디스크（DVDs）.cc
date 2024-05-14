#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e5, INF = 1e7;
ll t,n,k,h;
ll arrmin[MAXN] , arrmax[MAXN];
void update(ll i, ll val){
  i+=h;
  arrmin[i] = val;
  arrmax[i] = val;
  while(i>1){
    i/=2;
    arrmin[i] = min(arrmin[i*2],arrmin[i*2+1]);
    arrmax[i] = max(arrmax[i*2],arrmax[i*2+1]);
  }
}
ll calmin(ll l , ll r, ll nodenum ,ll nodel, ll noder){
  if(nodel >r || noder < l) return INF;
  if(l <= nodel && noder <= r) return arrmin[nodenum];
  ll mid = (nodel + noder)/2;
  return min(calmin(l,r,nodenum*2,nodel,mid),calmin(l,r,nodenum*2+1,mid+1,noder));
}
ll calmax(ll l , ll r, ll nodenum ,ll nodel, ll noder){
  if(nodel >r || noder < l) return -1;
  if(l <= nodel && noder <= r) return arrmax[nodenum];
  ll mid = (nodel + noder)/2;
  return max(calmax(l,r,nodenum*2,nodel,mid),calmax(l,r,nodenum*2+1,mid+1,noder));
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while(t--){
    cin >> n >> k;
    h = 1 << ((int)ceil(log2(n)));
    for(int i=h;i<h+n;i++){
      arrmin[i]=i-h;
      arrmax[i]=i-h;
    }
    for(int i=h+n;i<2*h;i++){
      arrmin[i]=INF;
      arrmax[i]=-1;
    }
    for(int i=h-1;i>0;i--){
      arrmin[i]= min(arrmin[i*2],arrmin[i*2+1]);
      arrmax[i]= max(arrmax[i*2],arrmax[i*2+1]);
    }
    while(k--){
      ll q, a,b;
      cin >> q >> a >> b;
      if(q==0){
        ll past_a = arrmin[a+h], past_b = arrmin[b+h];
        update(a,past_b);
        update(b,past_a);
      }
      else{
        ll mn = calmin(a,b,1,0,h-1);
        ll mx = calmax(a,b,1,0,h-1);
        if(mn==a && mx==b) cout << "YES" << endl;
        else cout << "NO" << endl;
      }
    }
  }
}