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
  int n, m ,r;
  cin >> n >> m >> r;
  vector <int> a[n], vis(n,0);
  while(m--){
    int x,y;
    cin >> x >> y;
    a[x-1].push_back(y-1);
    a[y-1].push_back(x-1);
  }
  for(int i=0;i<n;i++){
    sort(a[i].begin(),a[i].end(),greater<>());
  }
  queue <int> q;
  q.push(r-1);
  vis[r-1] = 1;
  int order = 2;
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(int i=0;i<a[x].size();i++){
      int nx = a[x][i];
      if(vis[nx]) continue;
      q.push(nx);
      vis[nx] = order;
      order++;
    }
  }
  for(int i=0;i<n;i++){
    cout << vis[i] << endl;
  }
}  