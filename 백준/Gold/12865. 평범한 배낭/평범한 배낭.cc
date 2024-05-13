#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e5+5;
int dp[102][MAXN];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  cin >> n >> k;
  vector <pii> a(n+1);
  for(int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=k;j++){
      if(j<a[i].fi) dp[i][j] = dp[i-1][j];
      else{
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i].fi]+a[i].se);
      }
    }
  }
  cout << dp[n][k];
  
}  