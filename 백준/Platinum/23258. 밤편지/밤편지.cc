#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll edge[302][302][302];
const ll MAXN = 1e10;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,q;
  cin >> n>> q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      int d;
      cin >> d;
      if(i==j) edge[i][j][0] = 0;
      else if(d==0) edge[i][j][0] = MAXN;
      else edge[i][j][0] = d;
    }
  }
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
        edge[s][t][i]=min(edge[s][t][i-1],edge[s][i][i-1]+edge[i][t][i-1]);
      }
    }
  }
  while(q--){
    int c,s,e;
    cin >> c >> s >> e;
    if(edge[s][e][c-1]==MAXN) cout << -1 << endl;
    else cout << edge[s][e][c-1] << endl;
  }

}  