#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e8;
vector <pll> adj[802];
ll d[802];
int n,e, v1,v2;

int solve(int st, int ed){
  for(int i=1;i<=n;i++) d[i] = MAXN;
  d[st] = 0;
  priority_queue <pll, vector <pll>, greater<pll>> pq;
  pq.push({0,st});
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
  return d[ed];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> e;
  while(e--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    adj[b].push_back({c,a});
  }
  cin >> v1 >> v2;
  int ans = min(solve(1,v1)+solve(v2,n),solve(1,v2)+solve(v1,n))+solve(v1,v2);
  if(ans>=MAXN) cout << -1;
  else cout << ans;

}  