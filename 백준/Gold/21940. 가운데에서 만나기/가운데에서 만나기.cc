#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll edge[202][202];
const ll MAXN = 1e10;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m,k;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) if(i!=j)edge[i][j] = MAXN;
  }
  while(m--){
    ll a,b,c;
    cin >> a >> b >> c;
    edge[a][b] = min(edge[a][b],c);
  }
  cin >> k;
  vector <int> home(k);
  for(int i=0;i<k;i++) cin >> home[i];
  for(int i=1;i<=n;i++){
    for(int s=1;s<=n;s++){
      for(int t=1;t<=n;t++){
        if(edge[s][t]>edge[s][i]+edge[i][t]){
          edge[s][t]=edge[s][i]+edge[i][t];
        }
      }
    }
  }
  ll ans=MAXN*10;
  vector <int> cityans;
  for(int i=1;i<=n;i++){
    ll tot = 0;
    for(auto j : home){
      tot = max(tot,edge[i][j]+edge[j][i]);
    }
    if(tot<ans){
      ans = tot;
      cityans.clear();
      cityans.push_back(i);
    }
    else if(tot==ans){
      cityans.push_back(i);
    }
  }
  for(auto i : cityans) cout << i << " ";
}  