#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int sccindex[100001];
int indeg[100001];
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
  int v,e;
  cin >> v >> e;
  for(int i=1;i<=v;i++) adj[i].clear();
  for(int i=1;i<=v;i++) dfsn[i] = 0;
  cnt = 0, sccnum = 0;
  fill(indeg,indeg+v+1,0);
  fill(finished,finished+v+1,0);
  for(int i=0;i<e;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i=1;i<=v;i++){
    if(dfsn[i]==0)dfs(i);
  }
  for(int i=1;i<=v;i++){
    for(int j : adj[i]){
      if(sccindex[i]!=sccindex[j]){
        indeg[sccindex[j]]++;
      }
    }
  }
  int ans = 0;
  for(int i=0;i<sccnum;i++){
    if(indeg[i]==0) ans++;
  }
  cout << ans << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int repeat;
  cin >> repeat;
  while(repeat--){
    solve();
  }
}