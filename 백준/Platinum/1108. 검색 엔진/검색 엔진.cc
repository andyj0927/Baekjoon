#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int sccindex[2501];
int sccnum;
vector <int> inscc[2501];
int cnt;
int dfsn[2501];
int finished[2501];
map <string,int> mp;
stack <int> s;
vector <int> adj[2501];
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
      inscc[sccnum].push_back(tt);
      if(tt==cur){
        break;
      }
    }
    sccnum++;
  }
  return result;
}
void solve(){
  int n;
  cin >> n;
  int web = 0;
  for(int i=1;i<=n;i++){
    string st;
    cin >> st;
    if(mp.find(st)==mp.end()) mp[st] = ++web;
    int par;
    cin >> par;
    for(int j=0;j<par;j++){
      string into;
      cin >> into;
      if(mp.find(into)==mp.end()) mp[into] = ++web;
      adj[mp[into]].push_back(mp[st]);
    }
  }
  string tar;
  cin >> tar;
  for(int i=1;i<=web;i++){
    if(dfsn[i]==0)dfs(i);
  }
  vector <int> indegree(sccnum,0);
  vector <int> sadj[sccnum];
  vector <ll> sval(web+1,1);
  for(int i=1;i<=web;i++){
    for(int j : adj[i]){
      if(sccindex[i]!=sccindex[j]){
        sadj[sccindex[i]].push_back(sccindex[j]);
        indegree[sccindex[j]]++;
      }
    }
  }
  queue <int> q;
  for(int i=0;i<sccnum;i++){
    if(indegree[i]==0) q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : inscc[cur]){
      for(int j : adj[i]){
        if(sccindex[i]!=sccindex[j]) sval[j]+=sval[i];
      }
    }
    for(int next : sadj[cur]){
      if(--indegree[next]==0) q.push(next);
    }
  }
  cout << sval[mp[tar]];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}