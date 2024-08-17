#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
ll n,m;
int solve(ll mid, vector <ll> &a){
  vector <ll> dp(n+1,0);
  for(int i=1;i<=n;i++){
    if(i>=mid+1){
      dp[i] = max(dp[i-1],dp[i-mid-1]+a[i]);
    }
    else{
      dp[i] = max(dp[i-1],a[i]);
    }
  }
  if(dp[n]>=m) return 1;
  else return 0;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  vector <ll> a(n+1,0);
  for(int i=1;i<=n;i++) cin >> a[i];
  ll mx = 0, tot = 0, ans;
  for(int i=1;i<=n;i++){
    mx = max(mx,a[i]);
    tot+=a[i];
  }
  if(tot<m){
    cout << -1;
    return 0;
  }
  if(mx>=m){
    cout << "Free!";
    return 0;
  }
  ll l = 0, h = n-2;
  while(l<=h){
    ll mid = (l+h)/2;
    if(solve(mid,a)){
      ans = mid;
      l = mid+1;
    }
    else h = mid-1;
  }
  cout << ans;
}