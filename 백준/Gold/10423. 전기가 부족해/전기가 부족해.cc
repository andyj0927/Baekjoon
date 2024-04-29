#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector <tuple<ll,int,int>> edge;
ll n,m,k;
vector <int> p(1005,-1);

int find(int cur){
  if(p[cur]<0) return cur;
  p[cur] = find(p[cur]);
  return p[cur];
}
bool merge(int a, int b){
  a= find(a);
  b= find(b);
  if(a==b) return false;
  p[b] = a;
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  k--;
  int fir,sec;
  cin >> fir;
  while(k--){
    cin >> sec;
    bool bb = merge(fir,sec);
  }
  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    edge.push_back(make_tuple(w,u,v));
  }
  sort(edge.begin(),edge.end());
  ll ans=0 , cnt = k-1;
  for(int i=0;i<edge.size();i++){
    int u,v,w;
    tie(w,u,v) = edge[i];
    if(merge(u,v)){
      cnt++;
      ans+=w;
      if(cnt==n-1) break;
    }
  }
  cout << ans << endl;
}  