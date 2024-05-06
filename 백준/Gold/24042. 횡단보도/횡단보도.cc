#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;
vector <pll> adj[100002];
ll d[100002];
ll n,m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for(int i=0;i<m;i++){
    ll u,v;
    cin >> u >> v;
    adj[v].push_back({i,u});
    adj[u].push_back({i,v});
  }
  for(int i=1;i<=n;i++) d[i] = MAXN;
  d[1] = 0;
  priority_queue <pll,vector<pll>,greater<pll>> pq;
  pq.push({0,1});
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto nxt: adj[cur.second]){ 
      ll t;
      if(cur.first<=nxt.first){
        t = 0;
      }
      else{
        t = (cur.first-nxt.first-1)/m+1;
      }
      t = t*m+nxt.first+1;
      if(t< d[nxt.second]){
        d[nxt.second] = t;
        pq.push({d[nxt.second],nxt.second});
      }
    }
  }
  cout << d[n];
}  