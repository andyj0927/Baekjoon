#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int sccindex[301];
int sccnum;
int cnt;
int dfsn[301];
int finished[301];
stack <int> s;
vector <int> adj[301];
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
    while(1){
      int tt = s.top();
      s.pop();
      finished[tt] = true;
      sccindex[tt] = sccnum;
      if(tt==cur){
        break;
      }
    }
    sccnum++;
  }
  return result;
}
void solve(){
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) adj[i].clear();
  sccnum = 0, cnt = 0;
  fill(finished,finished+n+1,0);
  fill(dfsn,dfsn+n+1,0);
  for(int i=1;i<=n;i++){
    string st;
    cin >> st;
    for(int j=0;j<n;j++){
      if(i==j+1) continue;
      if(st[j]=='1'){
        adj[i].push_back(j+1);
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(dfsn[i]==0)dfs(i);
  }
  vector <int> inscc[sccnum];
  vector <pii> ans;
  for(int i=1;i<=n;i++){
    inscc[sccindex[i]].push_back(i);
  }
  vector <vector <int>> sadj(sccnum,vector <int> (sccnum,0));
  for(int i=1;i<=n;i++){
    for(int j : adj[i]){
      if(sccindex[i]==sccindex[j]) continue;
      sadj[sccindex[i]][sccindex[j]]=1;
    }
  }
  for(int k=0;k<sccnum;k++){
    for(int i=0;i<sccnum;i++){
      for(int j=0;j<sccnum;j++){
        if(sadj[i][j]&&sadj[i][k]&&sadj[k][j]) sadj[i][j]=0;
      }
    }
  }
  for(int i=0;i<sccnum;i++){
    for(int j=0;j<sccnum;j++){
      if(sadj[i][j]){
        ans.push_back({inscc[i][0],inscc[j][0]});
      }
    }
  }
  for(int i=0;i<sccnum;i++){
    if(inscc[i].size()>1){
      for(int j=0;j<inscc[i].size();j++){
        ans.push_back({inscc[i][j],inscc[i][(j+1)%inscc[i].size()]});
      }
    }
  }
  cout << ans.size() << endl;
  for(auto i : ans){
    cout << i.first << " " << i.second << endl;
  }
  cout << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int repeat;
  cin >> repeat;
  while(repeat--){
    solve();
  }
}