#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 8e6, INF = 1e7;
ll n,m,h;
ll arr[MAXN], a[100005];
void update(ll i, ll val){
  i+=h;
  arr[i]+=val;
  while(i>1){
    i/=2;
    arr[i] = arr[i*2]+arr[i*2+1];
  }
}
ll cal(ll val, ll nodenum ,ll nodel, ll noder){
  arr[nodenum]--;
  if(nodel==noder) return nodenum-h+1;
  ll mid = (nodel+noder)/2;
  if(arr[nodenum*2]>=val) return cal(val,nodenum*2,nodel,mid);
  else return cal(val-arr[nodenum*2],nodenum*2+1,mid+1,noder);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  h= 1 << ((int)ceil(log2(2000000)));
  while(n--){
    int q,x;
    cin >> q >> x;
    if(q==1){
      update(x-1,1);
    }
    else{
      ll ans = cal(x,1,0,h-1);
      cout << ans << endl;
    }
    
  }

}