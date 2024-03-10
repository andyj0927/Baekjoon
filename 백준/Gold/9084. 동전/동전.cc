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
  ll t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin >>a[i];
    cin >> m;
    vector <int> dp(m+1,0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
      for(int j=1;j<=m;j++){
        if(j-a[i]<0) continue;
        dp[j] += dp[j-a[i]];
      }
    }
    cout << dp[m] << endl;
  }

}  
