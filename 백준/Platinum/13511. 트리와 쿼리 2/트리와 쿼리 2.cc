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
ll plen[100001][19];
int depth[100001];
int n;
void dfs(int cur, int par){
  for(auto next : adj[cur]){
    if(next.first!=par){
      p[next.first][0] = cur;
      plen[next.first][0] = next.second;
      depth[next.first] = depth[cur]+1;
      dfs(next.first,cur);
    }
  }
}
pll lca(int u, int v){
  if(depth[v]>depth[u]) swap(u,v);
  int diff = depth[u]-depth[v];
  ll dist = 0;
  for(int i=18;i>=0;i--){
    if((diff>>i)&1){
      dist+=plen[u][i];
      u = p[u][i];
    }
  }
  if(u!=v){
    for(int i=18;i>=0;i--){
      if(p[u][i]!=p[v][i]){
        dist+=plen[u][i];
        dist+=plen[v][i];
        u = p[u][i];
        v = p[v][i];
      }
    }
    dist+=plen[u][0];
    dist+=plen[v][0];
    u = p[u][0];
  }
  return {u,dist};
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
  plen[1][0] = 0;
  dfs(1,-1);
  for(int i=1;i<19;i++){
    for(int j=1;j<=n;j++){
      p[j][i] = p[p[j][i-1]][i-1];
      plen[j][i] = plen[j][i-1]+plen[p[j][i-1]][i-1];
    }
  }
  int m;
  cin >> m;
  while(m--){
    int q;
    cin >> q;
    if(q==1){
          int u,v;
          cin >> u >> v;
          auto par = lca(u,v);
          cout << par.second << endl;
    }
    else{
      int u,v,k;
      cin >> u >> v >> k;
      k--;
      auto [par,val] = lca(u,v);
      ll dist;
      if(depth[u]-depth[par]>=k){
        dist = k;
        for(int i=18;i>=0;i--){
          if((dist>>i)&1){
            u = p[u][i];
          }
        }
        cout << u << endl;
      }
      else{
        dist = depth[u]+depth[v]-2*depth[par]-k;
        for(int i=18;i>=0;i--){
          if((dist>>i)&1){
            v = p[v][i];
          }
        }
        cout << v << endl;
      }
    }

  }
}