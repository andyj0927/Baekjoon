#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[22][22];
int b[22][22];
int c[22][22];
int ans = 0;
int n;
void trans(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      c[i][j] = b[i][j];
      b[i][j] = 0;
    }
  }
  for(int i=0;i<n;i++){
    int be = 0;
    int k=-1;
    for(int j=0;j<n;j++){
      if(c[i][j]!=0){
        if(be!=c[i][j]){
          k++;
          b[i][k] = c[i][j];
          be = c[i][j];
        }
        else{
          b[i][k]+=be;
          be=0;
        }
      }
    }
  }
}
void rotate(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      c[i][j] = b[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      b[j][n-1-i] = c[i][j];
    }
  }
}
void pri(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}
void check(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ans = max(ans,b[i][j]);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  check();
  for(int s=0;s<1024;s++){
    int nx = s;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        b[i][j] = a[i][j];
      }
    }
    for(int t=0;t<5;t++){
      int d = nx%4;
      nx = nx/4;
      for(int k=0;k<d;k++){
        rotate();
      }
      trans();
      check();
    }
  }

  cout << ans;

}