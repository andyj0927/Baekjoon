#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
vector <int> a[100001];
int vis[100001];
void dfs(int cur){
  vis[cur] = 1;
  for(int i : a[cur]){
    if(vis[i]){
      continue;
    }
    dfs(i);
  }
}
int main(){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.tie( NULL );
  cin >> n;
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    int v,u;
    cin >> v >> u;
    a[v].push_back(u);
    a[u].push_back(v);
  }
  int treenum=0;
  for(int i=1;i<=n;i++){
    if(vis[i]) continue;
    treenum++;
    dfs(i);
  }
  cout << treenum-1 + (m+treenum-n);
}  