#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <ll> sum;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n),b(n),c(n),d(n);
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      sum.push_back(c[i]+d[j]);
    }
  }
  sort(sum.begin(),sum.end());
  ll ans = 0;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ll cnt = upper_bound(sum.begin(),sum.end(),-a[i]-b[j])-lower_bound(sum.begin(),sum.end(),-a[i]-b[j]);
      ans+=cnt;
    }
  }
  cout << ans << endl;
}  