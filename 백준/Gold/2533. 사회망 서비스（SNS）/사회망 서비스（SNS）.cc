#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, ans;
vector <int> a[1000001];
int ch[1000001];
int dfs(int cur,int par){
  for(int i : a[cur]){
    if(i!=par){
      ch[cur]+=dfs(i,cur);
    }
  }
  if(ch[cur]==0) return 1;
  else{
    ans++;
    return 0;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n-1;i++){
    int v,u;
    cin >> v >> u;
    a[v].push_back(u);
    a[u].push_back(v);
  }
  int t = dfs(1,-1);
  cout << ans;
}  