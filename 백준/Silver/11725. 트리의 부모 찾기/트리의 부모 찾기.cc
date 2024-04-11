#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector <int> a[100005];
int p[100005];

void dfs(int cur, int par){
  p[cur] = par;
  for(int i : a[cur]){
    if(i!=par){
      dfs(i,cur);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++){
    int v,u;
    cin >> v >> u;
    a[v].push_back(u);
    a[u].push_back(v);
  }
  dfs(1,0);
  for(int i=2;i<=n;i++){
    cout << p[i]<<endl;
  }
}  