#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll edge[102][102], nextcity[102][102];
const ll MAXN = 1e8;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++) if(i!=j)edge[i][j] = MAXN;
  }
  while(m--){
    ll a,b,c;
    cin >> a >> b >> c;
    edge[a][b] = min(edge[a][b],c);
    nextcity[a][b] = b;
  }
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
        if(edge[s][t]>edge[s][i]+edge[i][t]){
          edge[s][t]=edge[s][i]+edge[i][t];
          nextcity[s][t] = nextcity[s][i];
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(edge[i][j]==MAXN){
        edge[i][j] = 0;
      }
      cout << edge[i][j] << " ";
    }
    cout << endl;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(edge[i][j]==0){
        cout << 0 << endl;
        continue;
      }
      vector <int> path;
      int track = i;
      while(track!=j){
        path.push_back(track);
        track = nextcity[track][j];
      }
      path.push_back(track);
      cout << path.size() << " ";
      for(auto pathele : path){
        cout << pathele << " ";
      }
      cout << endl;
    }
  }

}  