#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
vector <ll> adj[100001];
vector <ll> lcadj[200001];
int p[200002][20];
int par[200002];
int depth[200002];
int big[200002];
int child[200002];
int n,m,idx;
ll dfs(int cur, int par){
  ll tot = 0;
  if(cur<=n) tot+=1;
  for(auto next : lcadj[cur]){
    if(next!=par){
      p[next][0] = cur;
      depth[next] = depth[cur]+1;
      tot+=dfs(next,cur);
    }
  }
  return child[cur] = tot;
}
ll lca(int u, int v){
  if(depth[v]>depth[u]) swap(u,v);
  int diff = depth[u]-depth[v];
  ll dist = 0;
  for(int i=19;i>=0;i--){
    if((diff>>i)&1){
      u = p[u][i];
    }
  }
  if(u!=v){
    for(int i=19;i>=0;i--){
      if(p[u][i]!=p[v][i]){
        u = p[u][i];
        v = p[v][i];
      }
    }
    u = p[u][0];
    v= p[v][0];
  }
  if(u!=v) return -1;
  return u;
}
ll find(int cur){
  if(par[cur]<0) return cur;
  par[cur] = find(par[cur]);
  return par[cur];
}
void merge(int a,int b,int w){
  a = find(a);
  b = find(b);
  if(a!=b){
    par[b] = idx;
    par[a] = idx;
    big[idx]=w;
    lcadj[b].push_back(idx);
    lcadj[a].push_back(idx);
    lcadj[idx].push_back(a);
    lcadj[idx].push_back(b);
    idx++;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq;
  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back(v);
    adj[v].push_back(u);
    pq.push({w,u,v});
  }
  idx = n+1;
  fill(par,par+2*n+1,-1);
  while(!pq.empty()){
    auto [w,u,v] = pq.top();
    pq.pop();
    if(find(u)!=find(v)){
      merge(u,v,w);
    }
  }
  idx--;
  for(int i=1;i<=idx;i++){
    if(par[i]<0){
      p[i][0] = i;
      depth[i] = 0;
      ll kk = dfs(i,-1);
    }
  }
  for(int i=1;i<=19;i++){
    for(int j=1;j<=idx;j++){
      p[j][i] = p[p[j][i-1]][i-1];
    }
  }
  int q;
  cin >> q;
  while(q--){
    int x,y;
    cin >> x >> y;
    int ca = lca(x,y);
    if(ca==-1) cout << -1 << endl;
    else cout << big[ca] << " " << child[ca] << endl;
  }
}