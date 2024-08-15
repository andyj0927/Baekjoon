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
  int n,k;
  cin >> n >> k;
  vector <ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  deque <ll> dq;
  for(int i=0;i<n;i++){
    dp[i] = a[i];
    if(!dq.empty()){
      dp[i] = max(dp[i],dp[dq.front()]+a[i]);
    }
    while(!dq.empty() && dp[dq.back()]<=dp[i]){
      dq.pop_back();
    }
    dq.push_back(i);
    while(dq.front()<i-k+1) dq.pop_front();
  }
  ll ans = -MOD;
  for(int i=0;i<n;i++) ans = max(ans,dp[i]);
  cout << ans;
}