#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int const MAXN = 1e6+5;
ll a[MAXN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll mx = a[n];
    ll ans = 0;
    for(int i=n-1;i>=1;i--){
      if(mx>a[i]){
        ans+=(mx-a[i]);
      }
      mx = max(mx,a[i]);
    }
    cout << ans << endl;
  }

}  