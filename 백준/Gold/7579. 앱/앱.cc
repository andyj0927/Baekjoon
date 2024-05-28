#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e6;
ll d[101][10001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m;
  cin >> n >> m;
  vector <ll> a(n+1,0), c(n+1,0);
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++) cin >> c[i];
  for(int i=1;i<=n;i++){
    for(int j=0;j<=10000;j++){
      d[i][j] = d[i-1][j];
      if(j>=c[i])d[i][j] = max(d[i-1][j-c[i]]+a[i],d[i-1][j]);
    }
  }
  for(int i=0;i<=10000;i++){
    if(d[n][i]>=m){
      cout << i;
      break;
    }
  }
}