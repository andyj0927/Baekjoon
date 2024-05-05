#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e8;
vector <pii> adj[20005];
int d[20005];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int v,e,k;
  cin >> v >> e >> k;
  while(e--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({c,b});
  }
  for(int i=1;i<=v;i++) d[i] = MAXN;
  priority_queue <pii, vector<pii>,greater<pii>> pq;
  pq.push({0,k});
  d[k] = 0;
  while(!pq.empty()){
    auto cur = pq.top();
    pq.pop();
    if(d[cur.second]!=cur.first) continue;
    for(auto edge : adj[cur.second]){
      int tar = edge.second;
      if(d[tar]>cur.first+edge.first){
        d[tar] = cur.first + edge.first;
        pq.push({d[tar],tar});
      }
    }
  }
  for(int i=1;i<=v;i++){
    if(d[i]==MAXN) cout << "INF" << endl;
    else cout << d[i] << endl;
  }

}  