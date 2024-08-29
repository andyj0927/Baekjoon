#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
vector <vector<int>> SCC;
int cnt;
int dfsn[10001];
bool finished[10001];
stack <int> s;
vector <int> adj[10001];
int ans;
int dfs(int cur){
  dfsn[cur] = ++cnt;
  s.push(cur);
  int result = dfsn[cur];
  for(auto next : adj[cur]){
    if(dfsn[next]==0){
      result = min(result,dfs(next));
    }
    else if(!finished[next]){
      result = min(result,dfsn[next]);
    }
  }
  if(result==dfsn[cur]){
    vector <int> sccunit;
    while(1){
      int tt = s.top();
      sccunit.push_back(s.top());
      s.pop();
      finished[tt] = true;
      if(tt==cur){
        break;
      }
    }
    sort(sccunit.begin(),sccunit.end());
    SCC.push_back(sccunit);
    ans++;
  }
  return result;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int v,e;
  cin >> v >> e;
  for(int i=0;i<e;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i=1;i<=v;i++){
    if(dfsn[i]==0)dfs(i);
  }
  cout << ans << endl;
  sort(SCC.begin(),SCC.end());
  for(auto i : SCC){
    for(auto j : i){
      cout << j << " ";
    }
    cout << -1 << endl;
  }
}