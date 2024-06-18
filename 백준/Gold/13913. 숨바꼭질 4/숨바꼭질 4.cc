#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e5+5;
int n,k;
int dp[MAXN],before[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for(int i=0;i<MAXN;i++) dp[i] = -1;
  cin >> n >> k;
  queue <int> q;
  q.push(n);
  dp[n] = 0;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : {cur-1,cur+1,cur*2}){
      if(i>200000 || i<0) continue;
      if(dp[i]!=-1) continue;
      dp[i] = dp[cur]+1;
      q.push(i);
      before[i] = cur;
    }
  }
  cout << dp[k] << endl;
  vector <int> ans;
  while(true){
    ans.push_back(k);
    if(k==n) break;
    k = before[k];
  }
  for(int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
}