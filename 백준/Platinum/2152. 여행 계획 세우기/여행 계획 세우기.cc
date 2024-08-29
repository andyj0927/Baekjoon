#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int sccindex[100001];
int sccnum;
int cnt;
int dfsn[100001];
int finished[100001];
stack <int> s;
vector <int> adj[100001];
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
void solve(){
  int n,m,s,t;
  cin >> n >> m >> s >> t;
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
  vector <int> indeg(sccnum,0);
  vector <int> sadj[sccnum];
  for(int i=1;i<=n;i++){
    for(int j : adj[i]){
      if(sccindex[i]==sccindex[j]) continue;
      indeg[sccindex[j]]++;
      sadj[sccindex[i]].push_back(sccindex[j]);
    }
  }
  vector <int> reachable(sccnum,0), snum(sccnum,0),smax(sccnum,0);
  reachable[sccindex[s]] =1;
  for(int i=1;i<=n;i++){
    snum[sccindex[i]]++;
  }
  smax[sccindex[s]] = snum[sccindex[s]];
  queue <int> q;
  for(int i=0;i<sccnum;i++){
    if(indeg[i]==0) q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int next : sadj[cur]){
      if(reachable[cur]){
        reachable[next] = 1;
        smax[next] = max(smax[next],smax[cur]+snum[next]);
      }
      indeg[next]--;
      if(indeg[next]==0) q.push(next);
    }
  }
  if(reachable[sccindex[t]]==0) cout << 0 << endl;
  else{
    cout << smax[sccindex[t]];
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}