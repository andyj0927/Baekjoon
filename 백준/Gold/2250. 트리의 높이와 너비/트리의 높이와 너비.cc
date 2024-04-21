#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
int big[10001];
int l[10001],r[10001],p[10001];
int cnt = 1, mn = 1, ans = 1;
void dfs(int cur,int dep){
  if(cur==-1) return;
  dfs(l[cur],dep+1);
  if(big[dep]==0){
    big[dep] = cnt;
  }
  else{
    int tot = cnt-big[dep]+1;
    if(tot>mn){
      mn = tot;
      ans = dep;
    }
    else if(tot==mn){
      ans = min(ans,dep);
    }
  }
  cnt+=1;
  dfs(r[cur],dep+1);
}
int main(){
  ios_base::sync_with_stdio( false );
  cin.tie( NULL );
  cout.tie( NULL );
  cin >> n;
  for(int i=1;i<=n;i++){
    int t;
    cin >> t;
    cin >> l[t] >> r[t];
    p[l[t]] = t;
    p[r[t]] = t;
  }
  int root = 1;
  while(p[root]!=0){
    root = p[root];
  }
  dfs(root,1);
  cout << ans << " " << mn;
}  