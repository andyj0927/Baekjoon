#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a[1001];
int deg[1001];
vector <int> ans;
ll n;
queue <int> q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m;
  cin >> n >> m;
  while(m--){
    int t;
    cin >> t;
    if(t==0) continue;
    int u;
    cin >> u;
    t--;
    while(t--){
      int v;
      cin >> v;
      a[u].push_back(v);
      deg[v]++;
      u = v;
    }
  }
  for(int i=1;i<=n;i++){
    if(deg[i]==0) q.push(i);
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    ans.push_back(cur);
    for(int i : a[cur]){
      deg[i]--;
      if(deg[i]==0) q.push(i);
    }
  }
  if(ans.size()!=n){
    cout << 0;
  }
  else{
    for(int i : ans){
      cout << i << endl;
    }
  }
}  