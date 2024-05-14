#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e5+5;
int dp1[2002][2002], dp2[2002][2002];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m, k;
  cin >> n >> m >> k;
  vector <string> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      dp1[i+1][j+1] = dp1[i+1][j]+dp1[i][j+1]-dp1[i][j];
      dp2[i+1][j+1] = dp2[i+1][j]+dp2[i][j+1]-dp2[i][j];
      if((i+j)%2==0){
        dp1[i+1][j+1]+= a[i][j]=='B' ? 1 : 0;
        dp2[i+1][j+1]+= a[i][j]=='W' ? 1 : 0;
      }
      else{
        dp1[i+1][j+1]+= a[i][j]=='W' ? 1 : 0;
        dp2[i+1][j+1]+= a[i][j]=='B' ? 1 : 0;
      }
    }
  }
  ll mx = 0;
  for(int i=k;i<=n;i++){
    for(int j=k;j<=m;j++){
      ll dp1ans = dp1[i][j]-dp1[i][j-k]-dp1[i-k][j]+dp1[i-k][j-k];
      ll dp2ans = dp2[i][j]-dp2[i][j-k]-dp2[i-k][j]+dp2[i-k][j-k];
      mx = max({mx,dp1ans,dp2ans});
    }
  }
  cout << k*k-mx;
}