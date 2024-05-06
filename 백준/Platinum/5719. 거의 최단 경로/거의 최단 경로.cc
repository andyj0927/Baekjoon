#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;
vector <pll> adj[502];
ll d[502];
vector <ll> pre[502];
ll n,m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(true){
    cin >> n >> m;
    for(int i=0;i<n;i++){
      adj[i].clear();
      pre[i].clear();
    }
    if(n==0 && m==0) break;
    ll s,ed;
    cin >> s >> ed;
    while(m--){
      ll u,v,p;
      cin >> u >> v >> p;
      adj[u].push_back({p,v});
    }
    priority_queue <pll, vector<pll>, greater<pll>> pq;
    for(int i=0;i<n;i++) d[i]=MAXN;
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
      auto cur = pq.top();
      pq.pop();
      if(d[cur.second]!=cur.first) continue;
      for(auto nxt: adj[cur.second]){
        if(d[nxt.second]>cur.first+nxt.first){
          d[nxt.second]= cur.first+nxt.first;
          pq.push({d[nxt.second],nxt.second});
          pre[nxt.second].clear();
          pre[nxt.second].push_back(cur.second);
        }
        else if(d[nxt.second]== cur.first+nxt.first){
          pre[nxt.second].push_back(cur.second);
        }
      }
    }
    if(d[ed]==MAXN){
      cout <<-1 << endl;
      continue;
    }
    queue <ll> q;
    q.push(ed);
    vector <bool> vis(n,false);
    while(!q.empty()){
      ll cur = q.front();
      q.pop();
      for(ll nxt : pre[cur]){
        for(int i=0;i<adj[nxt].size();i++){
          if(adj[nxt][i].second==cur){
            adj[nxt][i].first = MAXN+5;
          }
        }
        if(nxt!= s && vis[nxt]==false){q.push(nxt); vis[nxt] = true;}
      }
    }
    for(int i=0;i<n;i++) d[i]=MAXN;
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
      auto cur = pq.top();
      pq.pop();
      if(d[cur.second]!=cur.first) continue;
      for(auto nxt: adj[cur.second]){
        if(d[nxt.second]>cur.first+nxt.first){
          d[nxt.second]= cur.first+nxt.first;
          pq.push({d[nxt.second],nxt.second});
        }
      }
    }
    if(d[ed]==MAXN){
      cout <<-1 << endl;
    }
    else cout << d[ed] << endl;
  }
}  