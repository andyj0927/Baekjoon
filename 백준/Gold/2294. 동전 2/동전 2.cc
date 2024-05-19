#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e6;
int n,k;
int a[101];
int d[101][10001];
int f(int i, int j){
  if(i==0){
    if(j==0) return 0;
    else return MAXN;
  }
  if(d[i][j]!=-1) return d[i][j];
  int result = f(i-1,j);
  if(a[i]<=j) result = min(result,f(i,j-a[i])+1);
  d[i][j] = result;
  return result;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=0;i<=n;i++){
    for(int j = 0; j<=k;j++) d[i][j] = -1;
  }
  int ans = f(n,k);
  if(ans==MAXN) cout << -1;
  else cout << ans;
}