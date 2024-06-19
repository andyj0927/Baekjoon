#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e5+5;
int vis[1002][1002][11][2], a[1002][1002];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  queue <pair<pair<int,int>,pair<int,int>>> q;
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=1;i<=n;i++){
    string s;
    cin >> s;
    for(int j=0;j<m;j++){
      if(s[j]=='1') a[i][j+1] = 1;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      for(int x=0;x<=k;x++){
        for(int y=0;y<2;y++) vis[i][j][x][y] = -1;
      }
    }
  }
  vis[1][1][0][0] = 1;
  q.push({{1,1},{0,0}});
  while(!q.empty()){
    auto [p1,p2] = q.front();
    q.pop();
    auto [curx,cury] = p1;
    auto [curk,curd] = p2;
    for(int i=0;i<4;i++){
      int nx = curx+dx[i], ny = cury+dy[i];
      if(nx<=0 || ny<=0 || nx>n || ny>m) continue;
      if(a[nx][ny]==1){
        if(curd==1 || curk>=k) continue;
        if(vis[nx][ny][curk+1][!curd]!=-1) continue;
        vis[nx][ny][curk+1][!curd] = vis[curx][cury][curk][curd]+1;
        q.push({{nx,ny},{curk+1,!curd}});
      }
      else{
        if(vis[nx][ny][curk][!curd]!=-1) continue;
        vis[nx][ny][curk][!curd] = vis[curx][cury][curk][curd]+1;
        q.push({{nx,ny},{curk,!curd}});
      }
    }
    if(vis[curx][cury][curk][!curd]==-1){
      vis[curx][cury][curk][!curd] = vis[curx][cury][curk][curd]+1;
      q.push({{curx,cury},{curk,!curd}});
    } 
  }
  int ans = 1e9;
  for(int i=0;i<=k;i++){
    for(int j=0;j<2;j++){
      if(vis[n][m][i][j]!=-1) ans = min(ans,vis[n][m][i][j]);
    } 
  }
  if(ans==1e9) cout << -1;
  else cout << ans;
}