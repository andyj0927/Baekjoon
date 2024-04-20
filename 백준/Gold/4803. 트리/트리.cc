#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,m;
vector <int> a[501];
int vis[501];
int tree;
void dfs(int cur, int par){
  for(int i : a[cur]){
    if(vis[i]){
      if(i!=par) tree = 0;
      continue;
    }
    vis[i] = 1;
    dfs(i,cur);
  }
}
int main(){
  int t = 1;
  while(true){
    cin >> n >> m;
    if(n==0 && m == 0) break;
    for(int i=1;i<=n;i++){
      a[i].clear();
    }
    fill(vis,vis+n+1,0);
    for(int i=0;i<m;i++){
      int v,u;
      cin >> v >> u;
      a[v].push_back(u);
      a[u].push_back(v);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
      if(vis[i]) continue;
      tree=1;
      vis[i] = 1;
      dfs(i,-1);
      ans+=tree;
    }
    cout << "Case " << t << ": ";
    t++;
    if(ans>1){
      cout << "A forest of " << ans << " trees." << endl;
    }
    else if(ans==1){
      cout << "There is one tree." << endl;
    }
    else{
      cout <<"No trees." << endl;
    }
  }
}  