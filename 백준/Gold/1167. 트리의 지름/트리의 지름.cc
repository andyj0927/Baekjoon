#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <pll> a[100001];
ll n,mx = 0,ans=1;
void dfs(int cur,int par, int depth){
  if(depth>mx){
    mx = depth;
    ans = cur;
  }
  for(auto i : a[cur]){
    if(i.first!=par){
      dfs(i.first,cur,depth+i.second);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    int u,w;
    cin >> u;
    while(u!=-1){
      cin >> w;
      a[v].push_back({u,w});
      cin >> u;
    }
  }
  dfs(1,-1,0);
  mx = 0;
  dfs(ans,-1,0);
  cout << mx;
}  