#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e5+5;
int vis[102][102], cango[102][102], went[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  vector <pii> a[102][102];
  while(m--){
    int x,y,x1,y1;
    cin >> x >> y >> x1 >> y1;
    a[x][y].push_back({x1,y1});
  }
  vis[1][1] = 1;
  went[1][1] = 1;
  cango[1][1] = 1;
  queue<pii> q;
  q.push({1,1});
  while(!q.empty()){
    auto [curx,cury] = q.front();
    q.pop();
    for(auto [onx,ony]: a[curx][cury]){
      cango[onx][ony] = 1;
      if(vis[onx][ony]) continue;
      if(went[onx][ony]){
        vis[onx][ony] = 1;
        q.push({onx,ony});
      }
    }
    for(int i=0;i<4;i++){
      int nx = curx+dx[i];
      int ny = cury+dy[i];
      if(nx<=0 || nx>n || ny<=0 || ny>n) continue;
      went[nx][ny] = 1;
      if(vis[nx][ny]!=0) continue;
      if(cango[nx][ny]==0) continue;
      q.push({nx,ny});
      vis[nx][ny] =1;
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) if(cango[i][j])ans++;
  }
  cout << ans;
}