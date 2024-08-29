#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int sccindex[500001];
int sccnum;
int cnt;
int dfsn[500001];
int finished[500001];
int restor[500001];
int scc_res[500001], scc_cash[500001];
int atm[500001];
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
void solve(){
  int v,e;
  cin >> v >> e;
  for(int i=0;i<e;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i=1;i<=v;i++) cin >> atm[i];
  int st ,p;
  cin >> st >> p;
  for(int i=0;i<p;i++){
    int x;
    cin >> x;
    restor[x] = 1;
  }
  for(int i=1;i<=v;i++){
    if(dfsn[i]==0)dfs(i);
  }
  for(int i=1;i<=v;i++){
    scc_cash[sccindex[i]]+=atm[i];
    scc_res[sccindex[i]] |= restor[i];
  }
  vector <int> sadj[sccnum];
  vector <int> indeg(sccnum,0) , sccans(sccnum,0) , reachable(sccnum,0);
  for(int i=1;i<=v;i++){
    for(int j : adj[i]){
      if(sccindex[i]!=sccindex[j]){
        sadj[sccindex[i]].push_back(sccindex[j]);
        indeg[sccindex[j]]++;
      }
    }
  }
  queue <int> q;
  reachable[sccindex[st]] = 1;
  for(int i=0;i<sccnum;i++){
    sccans[i] = scc_cash[i];
    if(indeg[i]==0) q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(auto next : sadj[cur]){
      if(reachable[cur]){
        reachable[next] = 1;
        sccans[next] = max(sccans[next],sccans[cur]+scc_cash[next]);
      }
      indeg[next]--;
      if(indeg[next]==0) q.push(next);
    }

  }
  int ans=0;
  for(int i=0;i<sccnum;i++){
    if(reachable[i] && scc_res[i]) ans = max(ans,sccans[i]);
  }
  cout << ans;

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}