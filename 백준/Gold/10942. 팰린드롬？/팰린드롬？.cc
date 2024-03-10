#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dp[2005][2005];
string s[1001];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int m;
  cin >> m;
  for(int i=0;i<=n;i++){
    for(int j=0;j+i<=n;j++){
      if(i==1 || i==0) dp[j][i]=1;
      else{
        if(a[j]==a[j+i-1] && dp[j+1][i-2]) dp[j][i] = 1;
      }
    }
  }
  while(m--){
    int s,e;
    cin >> s >> e;
    cout << dp[s-1][e-s+1] << endl;
  }

}  
