#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e12;
vector <pll> adj[100002];
ll d[100002];
int m,n,k;
void solve(const vector<int> &meet){
  for(int i=1;i<=n;i++) d[i] = MAXN;
  priority_queue <pll, vector <pll>, greater<pll>> pq;
  for(int i=0;i<k;i++){
    d[meet[i]] = 0;
    pq.push({0,meet[i]});
  }
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto nxt : adj[cur.second]){
      if(d[nxt.second]>cur.first+nxt.first){
        d[nxt.second] = cur.first+nxt.first;
        pq.push({d[nxt.second],nxt.second});
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  while(m--){
    int u,v,c;
    cin >> u >> v >> c;
    adj[v].push_back({c,u});
  }
  vector <int> meet(k);
  for(int i=0;i<k;i++) cin >> meet[i];
  solve(meet);
  ll ans = 0, farest = 0;
  for(int i=1;i<=n;i++){
    if(ans<d[i]){
      farest = i;
      ans = d[i];
    }
  }
  cout << farest << endl << ans;
}  