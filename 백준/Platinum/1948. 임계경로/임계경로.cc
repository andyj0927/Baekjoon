#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <pii> adj[10001],re_adj[10001];
int deg[10001],ans[10001],edge,vis[10001];
ll n,m;
queue <int> q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
  cin >> n >> m;
  while(m--){
    int u,v,t;
    cin >> u >> v >> t;
    deg[v]++;
    adj[u].push_back({v,t});
    re_adj[v].push_back({u,t});
  }
  int st,ed;
  cin >> st >> ed;
  for(int i=1;i<=n;i++){
    if(i!=st && deg[i]==0) q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(auto [next,val] : adj[cur]){
        deg[next]--;
        if(deg[next]==0 && next!=st) q.push(next);
    }
  }
  q.push(st);
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(auto [next,val] : adj[cur]){
        deg[next]--;
        if(ans[next]<=ans[cur]+val){
             ans[next] = ans[cur]+val;
        }
        if(deg[next]==0) q.push(next);
    }
  }
  q.push(ed);
  vis[ed] = 1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(auto [next,val] : re_adj[cur]){
        if(ans[next]+val!=ans[cur]) continue;
        edge++;
        if(vis[next]==0){
            q.push(next);
            vis[next] = 1;
        }
    }
  }
  cout << ans[ed] << endl << edge;

}