#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dp[1001][1001];
string s[1001];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> s[i];
    s[i] = '0'+s[i];
  }
  int mx = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s[i][j]=='1') dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
      mx = max(dp[i][j],mx);
    }
  }
  cout << mx*mx;

}  
