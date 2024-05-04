#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll edge[102][102], item[102];
const ll MAXN = 1e8;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m,r;
  cin >> n >> m >> r;
  for(int i=1;i<=n;i++) cin >> item[i];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) if(i!=j)edge[i][j] = MAXN;
  }
  while(r--){
    ll a,b,c;
    cin >> a >> b >> c;
    edge[a][b] = min(edge[a][b],c);
    edge[b][a] = min(edge[b][a],c);
  }
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
        if(edge[s][t]>edge[s][i]+edge[i][t]){
          edge[s][t]=edge[s][i]+edge[i][t];
        }
      }
    }
  }
  ll ans = 0;
  for(int i=1;i<=n;i++){
    ll tot = 0;
    for(int j=1;j<=n;j++){
      if(edge[i][j]<=m) tot+=item[j];
    }
    ans = max(tot,ans);
  }
  cout << ans;
}  