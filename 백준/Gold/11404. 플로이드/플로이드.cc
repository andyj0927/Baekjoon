#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll edge[102][102];
const ll MAXN = 1e10;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) if(i!=j) edge[i][j] = MAXN;
  }
  for(int i=0;i<m;i++){
    ll x,y,z;
    cin >> x >> y >> z;
    edge[x][y] = min(z,edge[x][y]);
  }
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
        if(edge[s][t]>edge[s][i]+edge[i][t]){
          edge[s][t] = edge[s][i]+edge[i][t];
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(edge[i][j]==MAXN) cout << 0 << " ";
      else cout << edge[i][j] << " ";
    }
    cout << endl;
  }
}  