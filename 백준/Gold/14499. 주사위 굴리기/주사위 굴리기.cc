#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n,m,x,y,k;
int a[22][22];
int dice[6];

void spin(int t){
  int b[6];
  for(int i=0;i<6;i++){
    b[i] = dice[i];
  }
  if(t==1){
    if(y==m-1) return;
    y+=1;
    dice[1]= b[5];
    dice[0]= b[1];
    dice[2]= b[0];
    if(a[x][y]==0){
      a[x][y] = b[2];
      dice[5] = a[x][y];
    }
    else{
      dice[5] = a[x][y];
      a[x][y] = 0;
    }
  }
  else if(t==2){
    if(y==0) return;
    y-=1;
    dice[1]= b[0];
    dice[0]= b[2];
    dice[2]= b[5];
    if(a[x][y]==0){
      a[x][y] = b[1];
      dice[5] = a[x][y];
    }
    else{
      dice[5] = a[x][y];
      a[x][y] = 0;
    }
  }
  else if(t==3){
    if(x==0) return;
    x-=1;
    dice[3]= b[0];
    dice[0]= b[4];
    dice[4]= b[5];
    if(a[x][y]==0){
      a[x][y] = b[3];
      dice[5] = a[x][y];
    }
    else{
      dice[5] = a[x][y];
      a[x][y] = 0;
    }
  }
  else{
    if(x==n-1) return;
    x+=1;
    if(x<0) {x-=1; return;}
    dice[3]= b[5];
    dice[0]= b[3];
    dice[4]= b[0];
    if(a[x][y]==0){
      a[x][y] = b[4];
      dice[5] = a[x][y];
    }
    else{
      dice[5] = a[x][y];
      a[x][y] = 0;
    }
  }
  cout<< dice[0] <<endl;
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> x >> y >> k;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<k;i++){
    int t;
    cin >> t;
    spin(t);
  }
}