#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char s[4][8];
int k;
int vis[4];

void spin(int n,int m){
  if(vis[n]) return;
  vis[n]=1;
  if(n!=0){
    if(s[n][6]!=s[n-1][2]) spin(n-1,-1 * m);
  }
  if(n!=3){
    if(s[n][2]!=s[n+1][6]) spin(n+1,-1 * m);
  }
  if(m==1){
    char tmp = s[n][7];
    for(int i=7;i>=1;i--){
      s[n][i] = s[n][i-1];
    }
    s[n][0] = tmp;
  }
  else{
    char tmp = s[n][0];
    for(int i=0;i<7;i++){
      s[n][i] = s[n][i+1];
    }
    s[n][7] = tmp;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for(int i=0;i<4;i++){
    for(int j=0;j<8;j++){
      cin >> s[i][j];
    }
  }
  cin >> k;
  for(int i=0;i<k;i++){
    int n,m;
    cin >> n >> m;
    spin(n-1,m);
    vis[0] = 0;
    vis[1] = 0;
    vis[2] = 0;
    vis[3] = 0;
  }
  int ans = int(s[0][0]-'0')+2*int(s[1][0]-'0')+4*int(s[2][0]-'0')+8*int(s[3][0]-'0');
  cout << ans;
}