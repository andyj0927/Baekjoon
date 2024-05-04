#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll edge[22][22], newedge[22][22];
const ll MAXN = 1e10;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  ll ans = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) {cin >> edge[i][j]; newedge[i][j]=edge[i][j]; ans+=edge[i][j];}
  }
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
       if(i!=s && i!=t && edge[s][t]==edge[s][i]+edge[i][t]) {ans-=edge[s][t]; edge[s][t] = MAXN; }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
        edge[s][t] = min(edge[s][t],edge[s][i]+edge[i][t]);
      }
    }
  }
  int check = 1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(edge[i][j]!=newedge[i][j]) check = 0;
    }
  }
  if(check) cout << ans/2;
  else cout << -1;
}  