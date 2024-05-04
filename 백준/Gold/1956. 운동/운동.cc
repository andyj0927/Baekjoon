#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll edge[402][402];
const ll MAXN = 1e10;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) if(i!=j)edge[i][j] = MAXN;
  }
  while(m--){
    ll a,b,c;
    cin >> a >> b >> c;
    edge[a][b] = min(edge[a][b],c);
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
  ll ans=MAXN*2;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j){
        ans=min(ans,edge[i][j]+edge[j][i]);
      }
    }
  }
  if(ans>=MAXN) cout << -1;
  else cout << ans;
}  