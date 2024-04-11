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
  int n,m;
  cin >> n >> m;
  vector <int> a[n+1];
  while(m--){
    int v,w;
    cin >> v >> w;
    a[v].push_back(w);
  }
  vector <int> ans1(n+1,0), ans2(n+1,0), vis(n+1,0);
  for(int i=1;i<=n;i++){
    fill(vis.begin()+1,vis.end(),0);
    queue <int> q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for( int j : a[cur]){
        if(vis[j]) continue;
        vis[j] = 1;
        ans1[i]++;
        ans2[j]++;
        q.push(j);
      }
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++){
    if(ans1[i]>=(n+1)/2 || ans2[i]>=(n+1)/2){
      ans++;
    }
  }
  cout << ans;

}  