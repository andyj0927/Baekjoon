#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 8e5;
ll t,n,m,h;
ll arr[MAXN] , a[100005];
void update(ll i, ll val){
  i+=h;
  arr[i] = val;
  while(i>1){
    i/=2;
    arr[i] = arr[i*2]+arr[i*2+1];
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
  cin >> t;
  while(t--){
    cin >> n >> m;
    h = 1 << ((int)ceil(log2(n+m)));
    for(int i=h;i<h+m;i++) arr[i] = 0;
    for(int i=h+m;i<h+n+m;i++){
      arr[i] = 1;
    }
    for(int i=1;i<=n;i++){
      a[i] = m+i-1;
    }
    for(int i=h-1;i>0;i--) arr[i] = arr[i*2]+arr[i*2+1];
    for(int i=0;i<m;i++){
      int x;
      cin >> x;
      cout << cal(0,a[x]-1,1,0,h-1) << " ";
      update(a[x],0);
      update(m-1-i,1);
      a[x] = m-1-i;
    }
    cout << endl;
  }
}