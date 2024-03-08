#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[501][501] , dp[501][501];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      cin >> a[i][j];
    }
  }
  dp[1][1] = a[1][1];
  for(int i=2;i<=n;i++){
    for(int j=1;j<=i;j++){
      dp[i][j] = max(dp[i-1][min(j,i-1)]+a[i][j],dp[i-1][max(j-1,1)]+a[i][j]);
    }
  }
  int ans = dp[n][1];
  for(int i=1;i<=n;i++){
    ans = max(ans,dp[n][i]);
  }

  cout << ans;

}  
