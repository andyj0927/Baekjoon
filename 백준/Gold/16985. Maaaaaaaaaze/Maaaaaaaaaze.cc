#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[4][5][5][5];
int maze[5][5][5];
int ans = 10000;
int dx[6]={0,0,0,0,1,-1};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={1,-1,0,0,0,0};
void solve(){
  int path[5][5][5]={0,};
  if(maze[0][0][0]==0 || maze[4][4][4]==0) return;
  queue <tuple<int,int,int>> q;
  q.push({0,0,0});
  path[0][0][0] = 1;
  while(!q.empty()){
    int x,y,z;
    tie(x,y,z) = q.front();
    q.pop();
    for(int i=0;i<6;i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      int nz = z+dz[i];
      if(nx<0 || ny<0 || nz<0 || nx>=5 || ny>=5 || nz>=5) continue;
      if(maze[nx][ny][nz]==0||path[nx][ny][nz]!=0) continue;
      if(nx==4 && ny==4 && nz==4){
        ans = min(ans,path[x][y][z]);
        return;
      }
      path[nx][ny][nz] = path[x][y][z] +1;
      q.push({nx,ny,nz});
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for(int k=0;k<5;k++){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        cin >> a[0][k][i][j];
      }
    }
  }
  for(int k=0;k<5;k++){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        a[1][k][i][j] = a[0][k][4-j][i];
      }
    }
  }
  for(int k=0;k<5;k++){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        a[2][k][i][j] = a[1][k][4-j][i];
      }
    }
  }
  for(int k=0;k<5;k++){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        a[3][k][i][j] = a[2][k][4-j][i];
      }
    }
  }
  int order[5] = {0,1,2,3,4};
  do{
    for(int i=0;i<1024;i++){
      int x = i;
      for(int j=0;j<5;j++){
        int d = x%4;
        x= x/4;
        for(int p=0;p<5;p++){
          for(int q=0;q<5;q++){
            maze[p][q][j]= a[d][order[j]][p][q];
          }
        }
      }
      solve();
    }
  }while(next_permutation(order,order+5));
  if(ans==10000) cout << -1;
  else cout << ans;
}  
