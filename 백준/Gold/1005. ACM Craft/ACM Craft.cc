#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector <int> a[1005];
int deg[1005];
ll d[1005];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    int k;
    cin >> k;
    priority_queue <pll,vector <pll>,greater<>> pq;
    for(int i=1;i<=n;i++) deg[i]=0;
    for(int i=1;i<=n;i++){
      cin >> d[i];
    }
    for(int i=1;i<=n;i++){
      a[i].clear();
    }
    while(k--){
      int x,y;
      cin >> x >> y;
      a[x].push_back(y);
      deg[y]++;
    }
    int w;
    cin >> w;
    for(int i=1;i<=n;i++){
      if(deg[i]==0) pq.push({d[i],i});
    }

    while(!pq.empty()){
      auto pqfr = pq.top();
      pq.pop();
      int cur = pqfr.second;
      ll tim  = pqfr.first;
      if(cur==w){
        cout << tim << endl;
        break;
      }
      for(int i : a[cur]){
        deg[i]--;
        if(deg[i]==0){
          pq.push({tim+d[i],i});
        }
      }
    }
  }

}  