#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> adj[501];
int deg[501];
int ans[501],be[501];
ll n;
queue <int> q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> ans[i];
    while(true){
        int x;
        cin >> x;
        if(x==-1) break;
        adj[x].push_back(i);
        deg[i]++;
    }
  }
  for(int i=1;i<=n;i++){
    if(deg[i]==0) q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : adj[cur]){
      deg[i]--;
      be[i] = max(be[i],be[cur]+ans[cur]);
      if(deg[i]==0){
        q.push(i);
      }
    }
  }
  for(int i=1;i<=n;i++) cout << be[i]+ans[i] << endl;
}  