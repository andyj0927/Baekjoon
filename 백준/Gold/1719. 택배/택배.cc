#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll edge[202][202], go[202][202];
const ll MAXN = 1e10;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n>> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j)edge[i][j] = MAXN;
    }
  }
  while(m--){
    ll a,b,c;
    cin >> a >> b >> c;
    edge[a][b] = min(edge[a][b],c);
    edge[b][a] = min(edge[b][a],c);
    go[a][b] = b;
    go[b][a] = a;
  }
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
        if(edge[s][t]>edge[s][i]+edge[i][t]){
          edge[s][t] = edge[s][i]+edge[i][t];
          go[s][t] = go[s][i];
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) cout << "- ";
      else cout << go[i][j] << " ";
    }
    cout << endl;
  }

}  