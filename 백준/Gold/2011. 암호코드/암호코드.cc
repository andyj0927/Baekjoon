#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[5001],dp[5002];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.length();
  for(int i=0;i<s.length();i++){
    a[i+1] = s[i]-'0';
  }
  dp[n+1] = 1;
  for(int i=n;i>=1;i--){
    if(a[i]==0) dp[i] = 0;
    else if(i!=n && ((a[i]==2 && a[i+1]<=6)|| a[i]<=1)) dp[i]= dp[i+1]+dp[i+2];
    else dp[i] = dp[i+1];
    dp[i]%=1000000;
  }
  cout << dp[1];
}  
