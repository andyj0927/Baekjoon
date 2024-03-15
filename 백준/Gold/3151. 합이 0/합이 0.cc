#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[10005];
int n;
ll ans = 0;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      ans+=(upper_bound(a+j+1,a+n,-a[i]-a[j])-lower_bound(a+j+1,a+n,-a[i]-a[j]));
    }
  }
  cout << ans << endl;
}  