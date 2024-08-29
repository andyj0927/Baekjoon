#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int sccindex[5001];
int sccnum;
int cnt;
int dfsn[5001];
int finished[5001];
stack <int> s;
vector <int> adj[500001];
int dfs(int cur){
  dfsn[cur] = ++cnt;
  s.push(cur);
  int result = dfsn[cur];
  for(auto next : adj[cur]){
    if(dfsn[next]==0){
      result = min(result,dfs(next));
    }
    else if(!finished[next]){
      result = min(result,dfsn[next]);
    }
  }
  if(result==dfsn[cur]){
    while(1){
      int tt = s.top();
      s.pop();
      finished[tt] = true;
      sccindex[tt] = sccnum;
      if(tt==cur){
        break;
      }
    }
    sccnum++;
  }
  return result;
}
void solve(int n){
  int m;
  cin >> m;
  for(int i=1;i<=n;i++) adj[i].clear();
  sccnum = 0, cnt = 0;
  fill(finished,finished+n+1,0);
  fill(dfsn,dfsn+n+1,0);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i=1;i<=n;i++){
    if(dfsn[i]==0)dfs(i);
  }
  vector <int> outdeg(sccnum,0);
  for(int i=1;i<=n;i++){
    for(int j : adj[i]){
      if(sccindex[i]==sccindex[j]) continue;
      outdeg[sccindex[i]]++;
    }
  }
  vector <int> ans;
  for(int i=1;i<=n;i++){
    if(outdeg[sccindex[i]]==0) ans.push_back(i);
  }
  sort(ans.begin(),ans.end());
  for(auto i : ans) cout << i << " ";
  cout << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(1){
    int t;
    cin >> t;
    if(t==0) break;
    solve(t);
  }
}