#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  while(k--){
    int v,e;
    cin >> v >> e;
    vector <int> a[v+1];
    vector <int> vis(v+1,0);
    while(e--){
      int x,y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    for(int i=1;i<=v;i++){
      if(vis[i]!=0) continue;
      queue <int> q;
      vis[i] = 1;
      q.push(i);
      while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int j : a[cur]){
          if(vis[j]) continue;
          q.push(j);
          vis[j] = (vis[cur]==1) ? 2 : 1;
        }
      }
    }
    int ans = 1;
    for(int i=1;i<=v;i++){
      for(int j : a[i]){
        if(vis[i]==vis[j]) ans = 0;
      }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
}  