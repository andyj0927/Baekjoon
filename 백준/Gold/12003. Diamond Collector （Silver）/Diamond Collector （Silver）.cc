#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;
ll n,k;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  vector <int> dp(n);
  vector <int> suf_dp(n);
  int ed = 0;
  for(int st=0;st<n;st++){
    while(ed<n && a[ed]-a[st]<=k){
      ed++;
    }
    dp[st] = ed-st;
  }
  suf_dp[n-1] = dp[n-1];
  for(int i=n-2;i>=0;i--){
    suf_dp[i] = max(suf_dp[i+1],dp[i]);
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    int cur = dp[i];
    if(dp[i]+i<n){
      cur += suf_dp[dp[i]+i];
    }
    ans = max(ans,cur);
  }
  cout << ans;
}  