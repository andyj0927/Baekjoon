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
  vector <ll> a(n+1,0),presum(n+1,0);
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++) presum[i] = presum[i-1]+a[i];
  deque <ll> dq;
  for(int i=1;i<=n;i++){
    dp[i] = presum[i];
    while(!dq.empty() && dp[dq.back()-1]-presum[dq.back()]<=dp[i-1]-presum[i]){
      dq.pop_back();
    }
    dq.push_back(i);
    while(dq.front()<i-k) dq.pop_front();
    if(i>=k+1){
      dp[i]+=(dp[dq.front()-1]-presum[dq.front()]);
    }
  }
  cout << dp[n];
  
}