#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a[501];
int vis[501];

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
  vis[1] = 1;
  queue <int> q;
  q.push(1);
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : a[cur]){
      if(vis[i]) continue;
      vis[i] = vis[cur]+1;
      q.push(i);
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(vis[i]==2 || vis[i]==3) ans++;
  }
  cout << ans;
}  