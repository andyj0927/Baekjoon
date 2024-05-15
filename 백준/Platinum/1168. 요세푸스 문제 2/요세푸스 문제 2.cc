#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 4e5, INF = 1e7;
ll n,k,h;
ll arr[MAXN];

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
  cin >> n >> k;
  h= 1 << ((int)ceil(log2(n)));
  for(int i=h;i<h+n;i++){
    arr[i] = 1;
  }
  for(int i=h-1;i>0;i--) arr[i] = arr[i*2]+arr[i*2+1];
  vector <ll> ans;
  ll idx = k-1;
  for(int i=n;i>=1;i--){
    idx%=i;
    ll anskey = cal(idx+1,1,0,h-1);
    idx+=k-1;
    ans.push_back(anskey);
  }
  cout << "<";
  for(int i=0;i<ans.size()-1;i++) cout << ans[i] << ", ";
  cout << ans[ans.size()-1];
  cout << ">";
}