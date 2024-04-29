#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector <tuple<double,int,int>> edge;
ll n,m;
vector <int> p(1005,-1);
vector <pair<int,int>> a(1005);
double dist(int x , int y){
  return sqrt(pow(a[x].fi-a[y].fi,2)+pow(a[x].se-a[y].se,2));
}
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
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      edge.push_back(make_tuple(dist(i,j),i,j));
    }
  }
  sort(edge.begin(),edge.end());
  double ans = 0;
  int cnt=0;
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    if(merge(x,y)){
      cnt++;
    }
  }
  for(int i=0;i<edge.size();i++){
    double w;
    int x,y;
    tie(w,x,y) = edge[i];
    if(merge(x,y)){
      cnt++;
      ans+=w;
      if(cnt==n-1) break;
    }
  }
  cout <<fixed << setprecision(2) << ans << endl;
}  