 #include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e6+5;
int vis[MAXN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  ll ans = n*(n-1)*(n-2);
  ans/=6;
  cout << ans << endl;
  cout << 3 << endl;
}  