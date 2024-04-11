#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,m,k;
vector <int> a[51], vis(51);
void dfs(int cur){
  vis[cur] = 1;
  for(int i: a[cur]){
    if(vis[i]) continue;
    dfs(i);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  vector <int> b(k);
  for(int i=0;i<k;i++) cin >> b[i];
  vector <int> y[m];
  for(int k=0;k<m;k++){
    int x;
    cin >> x;
    for(int i=0;i<x;i++){
      int z;
      cin >> z;
      y[k].push_back(z);
    }
    for(int i=0;i<x;i++){
      for(int j=0;j<x;j++){
        if(i!=j) a[y[k][i]].push_back(y[k][j]);
      }
    }
  }
  for(int i : b){
    if(vis[i]) continue;
    dfs(i);
  }
  int ans = 0;
  for(int i=0;i<m;i++){
    int check = 1;
    for(int j : y[i]){
      if(vis[j]) check = 0;
    }
    if(check) ans++;
  }
  cout << ans;

}  