#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e5;
const ll MOD = 1e9+7;
int board[1001][1001];
int dp[1001][1001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> board[i][j];
    }
  }
  for(int i=1;i<=m;i++){
    dp[1][i]=dp[1][i-1]+board[1][i];
  }
  for(int i=2;i<=n;i++){
    int l[1001],r[1001];
    l[1] = dp[i-1][1]+board[i][1];
    r[m] = dp[i-1][m]+board[i][m];
    for(int j=2;j<=m;j++){
      l[j] = max(l[j-1],dp[i-1][j])+board[i][j];
    }
    for(int j=m-1;j>=1;j--){
      r[j] = max(r[j+1],dp[i-1][j])+board[i][j];
    }
    for(int j=1;j<=m;j++) dp[i][j] = max(l[j],r[j]);
  }
  cout << dp[n][m];
}