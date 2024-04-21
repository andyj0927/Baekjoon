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
int ans[100001];
void dfs(int cur){
  for(int i : a[cur]){
    ans[i]+= ans[cur];
    dfs(i);
  }
}
int main(){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.tie( NULL );
  cin >> n;
  int m;
  cin >> m;
  for(int i=1;i<=n;i++){
    int v;
    cin >> v;
    if(v==-1) continue;
    a[v].push_back(i);
  }
  for(int i=0;i<m;i++){
    int j,w;
    cin >> j >> w;
    ans[j]+=w;
  }
  dfs(1);
  for(int i=1;i<=n;i++){
    cout << ans[i] << " ";
  }
}  