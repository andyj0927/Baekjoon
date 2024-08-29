#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int sccindex[100001];
int sccnum;
int cnt;
int dfsn[100001];
int finished[100001];
stack <int> s;
vector <int> adj[100001];
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
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) adj[i].clear();
  sccnum = 0, cnt = 0;
  fill(finished,finished+n+1,0);
  fill(dfsn,dfsn+n+1,0);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  for(int i=0;i<n;i++){
    if(dfsn[i]==0)dfs(i);
  }
  vector <int> indeg(sccnum,0);
  for(int i=0;i<n;i++){
    for(int j : adj[i]){
      if(sccindex[i]==sccindex[j]) continue;
      indeg[sccindex[j]]++;
    }
  }
  int scccnt=0, needscc;
  vector <int> ans;
  for(int i=0;i<sccnum;i++){
    if(indeg[i]==0){
      scccnt++;
      needscc = i;
    }
  }
  if(scccnt>1) cout << "Confused" << endl;
  else if(scccnt==1){
    for(int i=0;i<n;i++){
      if(sccindex[i]==needscc){
        ans.push_back(i);
      }
    }
    for(auto i : ans) cout << i << endl;
  }
  else{
    for(int i=0;i<n;i++) cout << i << endl;
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