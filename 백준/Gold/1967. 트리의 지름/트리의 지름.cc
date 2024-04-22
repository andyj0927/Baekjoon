#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <pii> a[10001];
int n,mx = 0,ans=1;
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
  for(int i=0;i<n-1;i++){
    int p,c,w;
    cin >> p >> c >> w;
    a[p].push_back({c,w});
    a[c].push_back({p,w});
  }
  dfs(1,-1,0);
  mx = 0;
  dfs(ans,-1,0);
  cout << mx;
}  