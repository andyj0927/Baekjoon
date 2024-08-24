#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
vector <pll> adj[40001];
int p[40001][16];
int depth[40001];
ll d_length[40001];
int n;
void dfs(int cur, int par){
  for(auto next : adj[cur]){
    if(next.first!=par){
      p[next.first][0] = cur;
      d_length[next.first] = d_length[cur]+next.second;
      depth[next.first] = depth[cur]+1;
      dfs(next.first,cur);
    }
  }
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
  d_length[1] = 0;
  dfs(1,-1);
  p[1][0] = 1;
  for(int i=1;i<16;i++){
    for(int j=1;j<=n;j++){
      p[j][i] = p[p[j][i-1]][i-1];
    }
  }
  int m;
  cin >> m;
  while(m--){
    int u,v;
    cin >> u >> v;
    int pastu = u , pastv = v;
    if(depth[v]>depth[u]) swap(u,v);
    ll diff = depth[u]-depth[v];
    for(int i=15;i>=0;i--){
      if((diff>>i)&1){
        u = p[u][i];
      }
    }
    if(u!=v){
      for(int i=15;i>=0;i--){
        if(p[v][i]!=p[u][i]){
          u = p[u][i];
          v = p[v][i];
        }
      }
      u = p[u][0];
    }
    cout << d_length[pastu]+d_length[pastv]-2*d_length[u] << endl;
  }
}