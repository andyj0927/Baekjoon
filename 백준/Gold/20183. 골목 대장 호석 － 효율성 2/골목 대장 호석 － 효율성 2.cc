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
ll m,n,a,b,c;
ll solve(ll mx){
  for(int i=1;i<=n;i++) d[i] = MAXN;
  priority_queue <pll, vector <pll>, greater<pll>> pq;
  d[a] = 0;
  pq.push({0,a});
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto nxt : adj[cur.second]){
      if(nxt.first>mx) continue;
      if(d[nxt.second]>cur.first+nxt.first){
        d[nxt.second] = cur.first+nxt.first;
        pq.push({d[nxt.second],nxt.second});
      }
    }
  }
  return d[b];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> a >> b >> c;
  while(m--){
    ll u,v,mon;
    cin >> u >> v >> mon;
    adj[v].push_back({mon,u});
    adj[u].push_back({mon,v});
  }
  ll low = 1, high = 1e9, ans= 1e10;
  while(low <= high){
    ll mid = (low+high)/2;
    ll tot = solve(mid);
    if(tot<=c){
      ans = min(ans,mid);
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  if(ans==1e10) cout << -1;
  else cout << ans;
}  