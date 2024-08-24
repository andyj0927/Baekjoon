#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
vector <ll> adj[30001];
int p[30001][16];
int depth[40001];
int n;
void dfs(int cur, int par){
  for(auto next : adj[cur]){
    if(next!=par){
      p[next][0] = cur;
      depth[next] = depth[cur]+1;
      dfs(next,cur);
    }
  }
}
int lca(int u, int v){
  if(depth[v]>depth[u]) swap(u,v);
  int diff = depth[u]-depth[v];
  for(int i=15;i>=0;i--){
    if((diff>>i)&1){
      u = p[u][i];
    }
  }
  if(u!=v){
    for(int i=15;i>=0;i--){
      if(p[u][i]!=p[v][i]){
        u = p[u][i];
        v = p[v][i];
      }
    }
    u = p[u][0];
  }
  return u;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  depth[1] = 0;
  dfs(1,-1);
  p[1][0] = 1;
  for(int i=1;i<16;i++){
    for(int j=1;j<=n;j++){
      p[j][i] = p[p[j][i-1]][i-1];
    }
  }
  int m;
  cin >> m;
  vector <int> a(m+1);
  ll ans = 0;
  a[0] = 1;
  for(int i=1;i<=m;i++) cin >> a[i];
  for(int i=1;i<=m;i++){
    ll t = lca(a[i],a[i-1]);
    ans+=(depth[a[i]]+depth[a[i-1]]-2*depth[t]);
  }
  cout << ans;
}