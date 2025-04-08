#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
typedef long long ll;
int board[21][21];
int dx[4]={0,1,0,-1}; 
int dy[4]={1,0,-1,0}; // direction 0 동 , 1 남 , 2 서 , 3북
int n,m,k;
int visited[21][21];
int dice[6] = {1,2,3,4,5,6}; 
int score(int x, int y){
  for(int i =0;i<n;i++){
    for(int j=0;j<m;j++){
      visited[i][j] = -1;
    }
  }
  queue <pair<int,int>> q;
  q.push({x,y});
  visited[x][y] = 1;
  int cnt = 1;
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nx = cur.first+dx[i];
      int ny = cur.second+dy[i];
      if(nx<0 || nx>=n || ny<0 || ny>=m){
        continue;
      }
      if(visited[nx][ny]==1) continue;
      if(board[nx][ny]!=board[x][y]) continue;
      cnt++;
      q.push({nx,ny});
      visited[nx][ny]=1;
    }
  }
  return cnt*board[x][y];
}
void change_dice(int direction){
  int olddice[6];
  for(int i=0;i<6;i++) olddice[i] = dice[i];
  if(direction==0){ // 동쪽방향으로 이동
    // 북쪽,서쪽 그대로
    // 윗면 -> 동쪽
    // 동쪽 -> 바닥
    // 바닥 -> 서쪽
    // 서쪽 -> 윗면
    // 윗면 0, 북쪽 1, 동쪽 2, 서쪽 3, 남쪽 4, 바닥5
    dice[2] = olddice[0];
    dice[5] = olddice[2];
    dice[3] = olddice[5];
    dice[0] = olddice[3];
  }
  else if(direction==1){ // 남쪽방향으로 이동
    // 동쪽 서쪽 그대로
    // 윗면 -> 남쪽
    // 남쪽 -> 바닥
    // 바닥 -> 북쪽
    // 북쪽 -> 윗면
    dice[4] = olddice[0];
    dice[5] = olddice[4];
    dice[1] = olddice[5];
    dice[0] = olddice[1];
  }
  else if(direction==2){ // 서쪽방향으로 이동
    dice[0] = olddice[2];
    dice[2] = olddice[5];
    dice[5] = olddice[3];
    dice[3] = olddice[0];
  }
  else{
    dice[0] = olddice[4];
    dice[4] = olddice[5];
    dice[5] = olddice[1];
    dice[1] = olddice[0];
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cin >> board[i][j];
  }
  int ans=0;
  int direction=0; // direction 이 0 인건 동쪽 방향, 1이면 남, 2면 서쪽, 3이면 북
  int x = 0, y=0;
  for(int i=0;i<k;i++){ // 앞에 벽이 있는 상태
    x+=dx[direction]; 
    y+=dy[direction]; // 1번 과정 
    if(x<0 || x>=n || y <0 || y>=m){ // 없는 칸으로 온거잖아 반대방향으로 한칸 원래 상태, 원래는 이제 반대방향으로 한칸가야하니까
      direction = (direction+2)%4;
      x+=2*dx[direction];
      y+=2*dy[direction];
    }
    ans+= score(x,y); // 2번 과정
    change_dice(direction); // 굴러갔으면 dice의 상태가 변할것
    if(dice[5]>board[x][y]){ //3번 과정 , dice[5] 가 주사위의 바닥면 숫자
      // 이동방향이 어떻게 바뀌어?
      direction = (direction+1)%4;
    }
    else if(dice[5]<board[x][y]){
      direction = (direction+3)%4;
    }
  }
  cout << ans;

}


// 우리 풀이 는 k 번 이동하면서 그 안에 bfs 를 계속 도는거잖아. k* n*m
// ans+=score()
// K*n*m

// 근데 내가 말한대로 int score[n][m]을 만들어서 미리 bfs를 한번 돌려서 저장을 해두면
// ans+=score[x][y]
// n*m + k