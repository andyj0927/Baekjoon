#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int vis[42][42];
int n,m,k ,r ,c , a[12][12];
int check(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(i+r-1>n) continue;
      if(j+c-1>m) continue;
      bool f = true;
      for(int x=1;x<=r;x++){
        for(int y=1;y<=c;y++){
          if(a[x][y]==0) continue;
          if(vis[i+x-1][j+y-1]){
            f = false;
          }
        }
      }
      if(f){
        for(int x=1;x<=r;x++){
          for(int y=1;y<=c;y++){
            if(a[x][y]) vis[i+x-1][j+y-1] = 1;
          }
        }
        return 1;
      }
    }
  }
  return 2;
}
void turn(){
  int tmp[12][12];
  int bigl = max(r,c);
  for(int i=1;i<=bigl;i++){
    for(int j=1;j<=bigl;j++){
      tmp[j][bigl-i+1] = a[i][j];
    }
  }
  if(r>=c){
    for(int i=1;i<=c;i++){
      for(int j=1;j<=r;j++){
        a[i][j] = tmp[i][j];
      }
    }
  }
  else{
    for(int i=1;i<=c;i++){
      for(int j=1;j<=r;j++){
        a[i][j] = tmp[i][j+c-r];
      }
    }
  }
  int vv;
  vv= c;
  c = r;
  r = vv;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for(int i=0;i<k;i++){
    cin >> r >> c;
    memset(a,-1,sizeof(a));
    for(int j=1;j<=r;j++){
      for(int l=1;l<=c;l++){
        cin >> a[j][l];
      }
    }
    for(int t = 0; t<4; t++){
      if(check()==1){
        break;
      }
      else{
        turn();
      }
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(vis[i][j]) ans++;
    }
  }
  cout << ans;
}