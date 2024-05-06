#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e8;
vector <pll> adj[10002];
ll d[10002];
int m,n;

int solve(int st, int ed){
  for(int i=0;i<=n*m-1;i++) d[i] = MAXN;
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
  int dx[4]={0,1,0,-1};
  int dy[4]={1,0,-1,0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m >> n;
  int a[101][101];
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<m;j++){
      a[i][j] = s[j]-'0';
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<4;k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(a[nx][ny]==0) adj[i*m+j].push_back({0,nx*m+ny});
        else adj[i*m+j].push_back({1,nx*m+ny});
      }
    }
  }

  cout << solve(0,n*m-1);

}  