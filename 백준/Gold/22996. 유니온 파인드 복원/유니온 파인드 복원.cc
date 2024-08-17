#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
ll n,q,m;
int par[300001];
vector <int> adj[300001];
void dfs(int cur, int p){
  for(auto next : adj[cur]){
    dfs(next,cur);
  }
  if(p!=cur){
    cout << 1 << " "<< cur << " " << p << endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  int one = 0;
  for(int i=1;i<=n;i++){
    cin >> par[i];
    if(par[i]!=i){adj[par[i]].push_back(i); one++;}
  }
  cin >> m;
  vector <int> a(m);
  for(int i=0;i<m;i++) cin >> a[i];
  vector <int> s;
  for(int i=1;i<=n;i++){
    if(par[i]==i) s.push_back(i);
  }
  cout << n << " " << q << endl;
  for(int i=0;i<m;i++){
    cout << 2 << " " << a[i] << endl;
  }
  for(int i=0;i<q-m-one;i++){
    cout << 1 << " " << 1 << " "<< 1 << endl;
  }
  for(auto i : s){
    dfs(i,par[i]);
  }
}