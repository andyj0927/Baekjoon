#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <int> t(n,0) , p(n,0), dp(n+2,0);
  for(int i=0;i<n;i++){
    cin >> t[i] >> p[i];
  }
  for(int i=n-1;i>=0;i--){
    if(t[i]+i>n){
      dp[i] = dp[min(i+1,n-1)];
    }
    else{
      dp[i] = max(dp[min(i+1,n-1)],dp[i+t[i]]+p[i]);
    }
  }
  cout << dp[0];

}  
