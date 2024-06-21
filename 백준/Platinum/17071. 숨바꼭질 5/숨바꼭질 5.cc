#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 5e5+2;
int vis[MAXN][2];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  cin >> n >> k;
  for(int i=0;i<=500000;i++){
    for(int j=0;j<2;j++) vis[i][j] = -1;
  }
  queue <pii> q;
  q.push({n,0});
  vis[n][0] =0;
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    for(int nxt : {cur.first-1,cur.first+1,cur.first*2}){
      if(nxt<0 || nxt>500000) continue;
      if(vis[nxt][!cur.second]!=-1) continue;
      vis[nxt][!cur.second] = vis[cur.first][cur.second]+1;
      q.push({nxt,!cur.second});
    }
  }
  int i = 0, flag = 1;
  while(k<=500000){
    if(vis[k][0]<=i && (i-vis[k][0])%2==0){
      cout << i;
      flag = 0;
      break;
    }
    if(vis[k][1]<=i && (i-vis[k][1])%2==0){
      cout << i;
      flag = 0;
      break;
    }
    i++;
    k+=i;
  }
  if(flag) cout << -1;
}