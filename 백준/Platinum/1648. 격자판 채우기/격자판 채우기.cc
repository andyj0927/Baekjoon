#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

int dp[225][1<<14];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  int total = 1 << m;
  dp[0][0] = 1;
  for(int i=0;i<n*m;i++){
    for(int status=0;status< total;status++){
      if((status&1)!=0){
        dp[i+1][status>>1] +=dp[i][status];
        dp[i+1][status>>1]%=9901;
        continue;
      }
      dp[i+1][(status>>1)|(1<<(m-1))]+=dp[i][status];
      dp[i+1][(status>>1)|(1<<(m-1))]%=9901;
      if((status&2)==0 && i<=n*m-2 && (i%m)!=m-1 && m!=1){
        dp[i+2][status>>2] +=dp[i][status];
        dp[i+2][status>>2]%=9901;
      }
    }
  }
  cout << dp[n*m][0];
}