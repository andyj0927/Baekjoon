#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;
vector <pll> adj[10002];
ll d[10002][21];
ll n,m,k;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m>>k;
  for(int i=0;i<m;i++){
    ll u,v,c;
    cin >> u >> v >> c;
    adj[v].push_back({c,u});
    adj[u].push_back({c,v});
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<=k;j++) d[i][j] = MAXN;
  }
  for(int j=0;j<=k;j++) d[1][j] = 0;
  priority_queue <tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> pq; // 값,k,n
  for(int j=0;j<=k;j++) pq.push({0,j,1});
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    ll x,y,z;
    tie(x,y,z) = cur;
    if(d[z][y]!=x) continue;
    for(auto nxt : adj[z]){
      if(y<k){
        if(d[nxt.second][y+1]>x){
          d[nxt.second][y+1] = x;
          pq.push({d[nxt.second][y+1],y+1,nxt.second});
        }
      }
      if(d[nxt.second][y]>x+nxt.first){
        d[nxt.second][y]=x+nxt.first;
        pq.push({d[nxt.second][y],y,nxt.second});
      }
    }
  }
  cout << d[n][k];
}  