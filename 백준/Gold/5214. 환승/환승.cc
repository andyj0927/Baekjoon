#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int vis[101005];
vector <int> a[101005];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,k,m;
  cin >> n >> k >> m;
  for(int i=0;i<m;i++){
    for(int j=0;j<k;j++){
      int x;
      cin >> x;
      a[i+n+1].push_back(x);
      a[x].push_back(i+n+1);
    }
  }
  queue <int> q;
  q.push(1);
  vis[1] =1 ;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : a[cur]){
      if(vis[i]) continue;
      vis[i] = i>n ? vis[cur] : vis[cur]+1;
      q.push(i);
    }
  }
  if(vis[n]) cout << vis[n];
  else cout << -1;
}  