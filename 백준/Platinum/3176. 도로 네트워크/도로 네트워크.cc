#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
vector <pll> adj[100001];
int p[100001][19];
int depth[100001];
int mn[100001][19] , mx[100001][19];
int n;
void dfs(int cur, int par){
  for(auto next : adj[cur]){
    if(next.first!=par){
      p[next.first][0] = cur;
      mn[next.first][0] = next.second;
      mx[next.first][0] = next.second;
      depth[next.first] = depth[cur]+1;
      dfs(next.first,cur);
    }
  }
}
pii lca(int u, int v){
  if(depth[v]>depth[u]) swap(u,v);
  int diff = depth[u]-depth[v];
  int mnans = 1000001, mxans = 0;
  for(int i=18;i>=0;i--){
    if((diff>>i)&1){
      mnans = min(mnans,mn[u][i]);
      mxans = max(mxans,mx[u][i]);
      u = p[u][i];
    }
  }
  if(u!=v){
    for(int i=18;i>=0;i--){
      if(p[u][i]!=p[v][i]){
        mnans = min({mnans,mn[u][i],mn[v][i]});
        mxans = max({mxans,mx[u][i],mx[v][i]});
        u = p[u][i];
        v = p[v][i];
      }
    }
    mnans = min({mnans,mn[u][0],mn[v][0]});
    mxans = max({mxans,mx[u][0],mx[v][0]});
    u = p[u][0];
  }
  return {mnans,mxans};
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n-1;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  depth[1] = 0;
  p[1][0] = 1;
  mn[1][0] = 1000001;
  mx[1][0] = 0;
  dfs(1,-1);
  for(int i=1;i<19;i++){
    for(int j=1;j<=n;j++){
      p[j][i] = p[p[j][i-1]][i-1];
      mn[j][i] = min(mn[j][i-1],mn[p[j][i-1]][i-1]);
      mx[j][i] = max(mx[j][i-1],mx[p[j][i-1]][i-1]);
    }
  }
  int m;
  cin >> m;
  while(m--){
    int u,v;
    cin >> u >> v;
    auto ans = lca(u,v);
    cout << ans.first << " " << ans.second << endl;
  }
}