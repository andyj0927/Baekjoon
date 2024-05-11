#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;
int n,m,k;
vector <pll> adj[1002];
multiset <ll> d[1002];
ll ind[1002];
ll ans[1002];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  priority_queue <pll, vector <pll>, greater<pll>> pq; // 값, 위
  while(m--){
    int a,b,w;
    cin >> a >> b >> w;
    adj[a].push_back({w,b});
  }
  d[1].insert(0);
  pq.push({0,1});
  fill(ans,ans+n+1,-1);
  while(!pq.empty()){
    auto [co,loc] = pq.top();
    pq.pop();
    if(ind[loc]==k) continue;
    if(*d[loc].begin()!=co) continue;
    if(ind[loc]==k-1){
      ans[loc] = co;
    }
    d[loc].erase(d[loc].find(co));
    ind[loc]++;
    for(auto [nxtco,nxtloc] : adj[loc]){
      if(d[nxtloc].size()<=k){
        d[nxtloc].insert(nxtco+co);
        pq.push({nxtco+co,nxtloc});
      }
      else{
        if(*prev(d[nxtloc].end())>nxtco+co){
          d[nxtloc].erase(prev(d[nxtloc].end()));
          d[nxtloc].insert(nxtco+co);
          pq.push({nxtco+co,nxtloc});
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(ans[i]==-1) cout << -1 << endl;
    else cout << ans[i] << endl;
  }


}  