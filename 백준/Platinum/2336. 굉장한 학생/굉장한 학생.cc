#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e6, INF = 1e7;
int n,h;
int arr[MAXN];
int a[500005], b[500005], c[500005];
void update(int i , int val){
  i+=h;
  arr[i] = val;
  while(i>1){
    i/=2;
    arr[i] = min(arr[i*2],arr[i*2+1]);
  }
}
int cal(int l, int r , int nodenum ,int nodel, int noder){
  if(nodel>r || noder<l) return INF;
  if(l <= nodel && noder <=r) return arr[nodenum];
  int mid = (nodel+noder)/2;
  return min(cal(l,r,nodenum*2,nodel,mid),cal(l,r,nodenum*2+1,mid+1,noder));
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  h = 1 << ((int)ceil(log2(n)));
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    b[x] = i;
  }
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    c[x] = i;
  }
  int ans = 0;
  for(int i=1;i<2*h;i++){
    arr[i] = INF;
  }
  for(int i=1;i<=n;i++){
    int cur = a[i];
    int q = cal(0,b[cur]-1,1,0,h-1);
    if(q>c[cur]){
      ans++;
    }
    update(b[cur]-1,c[cur]);
  }
  cout << ans;
}