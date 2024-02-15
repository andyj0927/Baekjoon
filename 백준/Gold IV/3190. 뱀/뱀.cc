#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
char x[10005];
int n,k,l;
int a[102][102],body[102][102];
int xdir[4] = {0,1,0,-1}, ydir[4]= {1,0,-1,0};
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fill(x,x+10002,'A');
  cin >> n >> k;
  for(int i=0;i<k;i++){
    int p,q;
    cin >> p >> q;
    a[p][q] = 1;
  }
  cin >> l;
  for(int i=0;i<l;i++){
    int p;
    char q;
    cin >> p >> q;
    x[p] = q;
  }
  int time = 1 , nx = 1, ny = 1 , look = 0;
  body[1][1] = 1;
  queue <pii> q;
  q.push({1,1});
  while(true){
    nx+=xdir[look];
    ny+=ydir[look];
    q.push({nx,ny});
    if(nx<=0 || nx>n || ny<=0 || ny>n){
      break;
    }
    if(body[nx][ny]){
      break;
    }
    body[nx][ny] = 1;
    if(a[nx][ny]){
      a[nx][ny] = 0;
    }
    else{
      auto tale = q.front();
      q.pop();
      body[tale.first][tale.second] = 0;
    }
    if(x[time]=='L'){
      look=(look+3)%4;
    }
    else if(x[time]=='D'){
      look = (look+1)%4;
    }
    time++;
  }
  cout << time;
}  
