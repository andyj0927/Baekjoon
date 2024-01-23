#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int c[52][52][15];
int a[52][52];
int use[15];
int n,m, k,ans = 3000000;

int check(){
  int cnt = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]==1){
        int mx = 200;
        for(int x=0;x<m;x++){
          mx = min(mx,c[i][j][use[x]]);
        }
        cnt+=mx;
      }
    }
  }
  return cnt;
}

void f(int x, int next){
  if(x==m){
    ans = min(ans,check());
    return;
  }
  for(int i=next;i<k;i++){
    use[x] = i;
    f(x+1,i+1);
  }
}

int dis(int x1,int y1,int x2, int y2){
  return abs(x1-x2)+abs(y1-y2);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]!=2) continue;
      for(int x= 0; x<n;x++){
        for(int y=0;y<n;y++){
          if(a[x][y]==1){
            c[x][y][k] = dis(x,y,i,j);
          }
        }
      }
      k++;
    }
  }
  f(0,0);
  cout << ans;

}