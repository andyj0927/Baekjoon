#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  vector <ll> x(n+1), y(n+1);
  for(int i=0;i<n;i++) cin >> x[i] >> y[i];
  ll ans = 0;
  x[n] = x[0];
  y[n] = y[0];
  for(int i=0;i<=n-1;i++){
    ans+=x[i]*y[i+1];
    ans-=x[i+1]*y[i];
  }
  double rans = llabs(ans)/2.0;
  cout << fixed << setprecision(1) << rans << endl;
}  