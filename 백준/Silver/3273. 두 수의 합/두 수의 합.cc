#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
ll cnt[2000001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
	int t;
	cin >> t;
	cnt[t]++;
  }
  int x;
  cin >> x;
  ll ans = 0;
  for(int i=1;i<=x;i++){
	ans += (cnt[i]*cnt[x-i]);
  }
  cout << ans/2;
}