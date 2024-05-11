#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;
int n,m,k,s,ed;
vector <pll> adj[1002];
ll d[1002][1002];
ll increase[30001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k >> s >> ed;
  priority_queue <tuple<ll,ll,ll>, vector <tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq; // 값, 걸린 횟수, 위
  while(m--){
    int a,b,w;
    cin >> a >> b >> w;
    adj[a].push_back({w,b});
    adj[b].push_back({w,a});
  }
  for(int i=1;i<=k;i++){
    cin >> increase[i];
    increase[i]+=increase[i-1];
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<=n;j++){
      d[i][j] = MAXN;
    }
  }
  d[s][0] = 0;
  pq.push({0,0,s});
  while(!pq.empty()){
    auto cur = pq.top();
    ll x,len,loc;
    tie(x,len,loc) = cur;
    pq.pop();
    if(d[loc][len]!=x) continue;
    if(len==n) continue;
    for(auto nxt : adj[loc]){
      if(d[nxt.second][len+1]>d[loc][len]+nxt.first){
        d[nxt.second][len+1]=d[loc][len]+nxt.first;
        pq.push({d[nxt.second][len+1],len+1,nxt.second});
      }
    }
  }
  for(int i=0;i<=k;i++){
    ll mn = MAXN;
    for(int j=0;j<=n;j++){
      mn = min(d[ed][j]+increase[i]*j,mn);
    }
    cout << mn << endl;
  }
}  