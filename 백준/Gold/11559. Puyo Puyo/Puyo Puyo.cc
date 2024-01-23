#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char a[12][6];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool check(){
  int vis[12][6]={0,};
  vector <int> del;
  int num = 1;
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      if(a[i][j]!='.' && !vis[i][j]){
        queue <pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = num;
        int cnt = 1;
        while(!q.empty()){
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for(int k = 0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0 || nx>=12 || ny<0 || ny>=6) continue;
            if(vis[nx][ny]) continue;
            if(a[nx][ny]==a[i][j]){
              vis[nx][ny] = num;
              q.push({nx,ny});
              cnt++;
            }
          }
        }
        if(cnt>=4) del.push_back(num);
        num++;
      }
    }
  }
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      for(int k : del){
        if(vis[i][j]==k){
          a[i][j]='.';
        }
      }
    }
  }
  if(del.size()) return true;
  else return false;
}

void gravity(){
  char b[12][6];
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      b[i][j]='.';
    }
  }
  for(int j=0;j<6;j++){
    int x=11;
    for(int i=11;i>=0;i--){
      if(a[i][j]!='.'){
        b[x][j] = a[i][j];
        x--;
      }
    }
  }
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      a[i][j] = b[i][j];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<12;i++){
    for(int j=0;j<6;j++){
      cin >> a[i][j];
    }
  }
  int ans = 0;

  while(check()){
    ans++;
    gravity();
  }
  cout << ans;
}