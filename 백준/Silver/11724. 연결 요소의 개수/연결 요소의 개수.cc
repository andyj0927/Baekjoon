#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a[1005];
int vis[1005];

void dfs(int cur){
  for(auto i : a[cur]){
    if(vis[i]!=-1) continue;
    vis[i]=1;
    dfs(i);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  fill(vis+1,vis+n+1,-1);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int ans = 0;
  for(int i =1;i<=n;i++){
    if(vis[i]!=-1) continue;
    ans+=1;
    vis[i]=1;
    dfs(i);
  }
  cout << ans;
}  