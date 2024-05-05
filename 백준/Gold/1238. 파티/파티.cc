#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e8;
vector <pll> adj[1002], inadj[1002];
ll d[1002], id[1002];
int v,e,x;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> v >> e >> x;
  while(e--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
    inadj[b].push_back({c,a});
  }
  for(int i=1;i<=v;i++) {d[i] = MAXN; id[i]=MAXN;}
  priority_queue <pii, vector<pii>,greater<pii>> pq;
  d[x] = 0;
  pq.push({0,x});
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto nxt : adj[cur.second]){
      if(d[nxt.second]>cur.first+nxt.first){
        d[nxt.second] = cur.first + nxt.first;
        pq.push({d[nxt.second],nxt.second});
      }
    }
  }
  pq.push({0,x});
  id[x] = 0;
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    if(id[cur.second]!=cur.first) continue;
    for(auto nxt : inadj[cur.second]){
      if(id[nxt.second]>cur.first+nxt.first){
        id[nxt.second] = cur.first + nxt.first;
        pq.push({id[nxt.second],nxt.second});
      }
    }
  }
  ll mx = 0;
  for(int i=1;i<=v;i++){
    mx = max(mx,d[i]+id[i]);
  }
  cout << mx;
}  