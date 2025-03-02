#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e5+1;
ll n, m;
int cnt;
class DSU {
public:
  vector <int> p;
  DSU(int n){
    p.resize(n+1);
    for(int i=1;i<=n;i++) p[i] = -1;
  }
  int find(int cur){
    if(p[cur]<0) return cur;
    p[cur] = find(p[cur]);
    return p[cur];
  }
  void merge(int i, int j){
    i = find(i);
    j = find(j);
    if(i==j) return;
    p[j] = i;
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  vector <int> cow(n+1,0);
  DSU dsu(n);
  for(int i=1;i<=n;i++) cin >> cow[i];
  for(int i=1;i<=n;i++){
    if(cow[i]!=i) cnt++;
  }
  priority_queue <tuple<int,int,int>> pq;
  for(int i=0;i<m;i++){
    int a,b,w;
    cin >> a >> b >> w;
    pq.push({w,a,b});
  }
  if(cnt==0){
    cout << -1;
    return 0;
  }
  int i = 1;
  while(!pq.empty()){
    auto [w,a,b] = pq.top();
    pq.pop();
    dsu.merge(a,b);
    while(i<=n && dsu.find(i)==dsu.find(cow[i])) i++;
    if(i==n+1){
      cout << w;
      break;
    }
    
  }

}  