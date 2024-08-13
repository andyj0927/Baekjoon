#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int dp[10001][10];
int n;
string st , ed;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> st >> ed;
  for(int i=0;i<=n;i++){
    for(int j=0;j<10;j++) dp[i][j] = MAXN;
  }
  dp[0][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<10;j++){
      if(dp[i-1][j]==MAXN) continue;
      int turn = (ed[i-1]-st[i-1]-j+20)%10;
      dp[i][j]=min(dp[i-1][j]+(10-turn)%10,dp[i][j]);
      dp[i][(j+turn)%10] = min(dp[i-1][j]+turn,dp[i][(j+turn)%10]);
    }
  }
  int ans = MAXN;
  for(int i=0;i<10;i++) ans= min(ans,dp[n][i]);
  cout << ans;
}