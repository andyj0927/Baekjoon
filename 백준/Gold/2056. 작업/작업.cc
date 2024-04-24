#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector <int> a[10005];
vector <int> t[1000005];
int times[10005], deg[10005];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> times[i];
    int m;
    cin >> m;
    while(m--){
      int v;
      cin >> v;
      a[v].push_back(i);
      deg[i]++;
    }
  }
  for(int i=1;i<=n;i++){
    if(deg[i]==0){
      t[times[i]].push_back(i);
    }
  }
  int ans = 0;
  for(int i=1;i<=1000001;i++){
    if(t[i].empty()) continue;
    ans = i;
    for(int j : t[i]){
      for(int k : a[j]){
        deg[k]--;
        if(deg[k]==0){
          t[i+times[k]].push_back(k);
        }
      }
    }
  }
  cout << ans;

}  