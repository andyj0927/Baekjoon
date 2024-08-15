#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
ll dp[100005];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int ans = 0;
  for(int i=0;i<n;i++){
    int g;
    cin >> g;
    ans^=g;
  }
  if(ans) cout << "koosaga" << endl;
  else cout << "cubelover" << endl;
}