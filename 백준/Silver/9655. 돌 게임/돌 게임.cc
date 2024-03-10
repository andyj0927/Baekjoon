#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dp[1001];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  dp[1] = 1;
  dp[2] = 0;
  dp[3] = 1;
  for(int i=4;i<=n;i++){
    if(dp[i-1]==0||dp[i-3]==0) dp[i] = 1;
    else dp[i] = 0;
  }
  if(dp[n]) cout << "SK";
  else cout << "CY";

}  
