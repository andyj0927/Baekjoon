#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int ans[8][8];
int piece[10][8][8];
int n,k,tot;
bool oob(int x, int y){
  if(x<0 || x>=n || y <0 || y>=n) return true;
  else return false;
}
int check(int a, int b){
  for(int ix=-n+1;ix<n;ix++){
    for(int iy=-n+1;iy<n;iy++){
      for(int jx=-n+1;jx<n;jx++){
        for(int jy=-n+1;jy<n;jy++){
          int check = 1, cnt = 0;
          vector <vector <int>> vis(n,vector <int>(n,0));
          for(int i=0;check && i<n;i++){
            for(int j=0;check && j<n;j++){
              int nix = i + ix, niy = j + iy , njx = i + jx , njy = j + jy;
              if(oob(nix,niy) && piece[a][i][j]==1) check = 0;
              if(oob(njx,njy) && piece[b][i][j]==1) check = 0;
              if(!oob(nix,niy) && piece[a][i][j]==1 && ans[nix][niy]==0) check = 0;
              if(!oob(njx,njy) && piece[b][i][j]==1 && ans[njx][njy]==0) check = 0;
              if(!oob(nix,niy) && piece[a][i][j]==1 && ans[nix][niy]){
                if(vis[nix][niy]) check = 0;
                else{
                  cnt++;
                  vis[nix][niy] = 1;
                }
              }
              if(!oob(njx,njy) && piece[b][i][j]==1 && ans[njx][njy]){
                if(vis[njx][njy]) check = 0;
                else{
                  cnt++;
                  vis[njx][njy] = 1;
                }
              }
            }
          }
          if(check && cnt==tot){
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<n;j++) if(s[j]=='#') {ans[i][j] = 1; tot++;}
  }
  for(int p=0;p<k;p++){
    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      for(int j=0;j<n;j++) if(s[j]=='#') piece[p][i][j] = 1;
    }
  }
  for(int f=0;f<k;f++){
    for(int s=f+1;s<k;s++){
      if(check(f,s)){
        cout << f+1 << " " << s+1 << endl;
        return 0;
      }
    }
  }
}