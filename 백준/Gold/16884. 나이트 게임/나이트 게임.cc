#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

void solve(){
  int n;
  cin >> n;
  if(n%2==1) cout << "koosaga" << endl;
  else cout << "cubelover" << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int repeat;
  cin >> repeat;
  while(repeat--){
    solve();
  }
}