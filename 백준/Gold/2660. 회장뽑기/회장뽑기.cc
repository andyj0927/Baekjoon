#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a[52];
int vis[52];
int n;
map <int,vector<int>> mp;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(true){
    int u,v;
    cin >> u >> v;
    if(u==-1 && v==-1) break;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for(int i=1;i<=n;i++){
    fill(vis+1,vis+n+1,0);
    queue <int> q;
    vis[i] = 1;
    q.push(i);
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      for(int j : a[cur]){
        if(vis[j]!=0) continue;
        vis[j]= vis[cur]+1;
        q.push(j);
      }
    }
    int mx = 0;
    for(int j=1;j<=n;j++){
      mx = max(mx,vis[j]);
    }
    mp[mx-1].push_back(i);
  }
  cout << mp.begin()->first << " " << (mp.begin()->second).size() << endl;
  for(auto i : mp.begin()->second){
    cout << i << " ";
  }

}  