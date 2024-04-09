#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a[101];
int vis[101];
int ans;
void dfs(int cur){
  vis[cur] = 1;
  ans+=1;
  for(auto i : a[cur]){
    if(vis[i]) continue;
    dfs(i);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1);
  cout << ans-1;
}  