#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
int m,n;
ll h[501][501];
ll d[501][501];
int dx[4] = {0,1,0,-1}, dy[4]={1,0,-1,0};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector <pair<int,pii>> a;
  cin >> m >> n;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin >> h[i][j];
      a.push_back({h[i][j],{i,j}});
    }
  }
  sort(a.begin(),a.end(),greater<>());
  d[0][0] = 1;
  for(int i=0;i<a.size();i++){
    int x = a[i].second.first, y = a[i].second.second;
    if(d[x][y]==0) continue;
    for(int j=0;j<4;j++){
      int nx = x+dx[j], ny = y+dy[j];
      if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
      if(h[nx][ny]<h[x][y])d[nx][ny]+=d[x][y];
    }
  }
  cout << d[m-1][n-1];
}