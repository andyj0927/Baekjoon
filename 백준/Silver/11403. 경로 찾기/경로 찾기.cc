#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[102][102];
int vis[102];
int n;
int ans;
void dfs(int cur, int val){
  vis[cur] = 1;
  for(int i=0;i<n;i++){
    if(a[cur][i]){
      if(i==val) ans = 1;
      if(vis[i]==0) dfs(i,val);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      fill(vis,vis+n,0);
      ans = 0;
      dfs(i,j);
      cout << ans << " ";
    }
    cout << endl;
  }
}  