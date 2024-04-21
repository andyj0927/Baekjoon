#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
vector <int> a[100001];
int sub[100001];
void dfs(int cur, int par){
  sub[cur] = 1;
  for(int i : a[cur]){
    if(i!=par){
      dfs(i,cur);
      sub[cur]+=sub[i];
    }
  }
}
int main(){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.tie( NULL );
  cin >> n;
  int r,q;
  cin >> r >> q;
  for(int i=0;i<n-1;i++){
    int v,u;
    cin >> v >> u;
    a[v].push_back(u);
    a[u].push_back(v);
  }
  dfs(r,-1);
  while(q--){
    int t;
    cin >> t;
    cout << sub[t] << endl;
  }
}  