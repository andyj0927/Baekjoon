#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector <tuple<ll,int,int>> edge;
ll n,m;
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
  cin >> n >> m;
  for(int i=0;i<=m;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    edge.push_back(make_tuple(c,a,b));
  }
  sort(edge.begin(),edge.end());
  ll cnt = 0, lans = 0, hans = 0;
  for(int i=0;i<edge.size();i++){
    ll w,a,b;
    tie(w,a,b) = edge[i];
    if(merge(a,b)){
      cnt++;
      hans+=w;
      if(cnt==n) break;
    }
  }
  hans = n-hans;
  cnt = 0;
  fill(p.begin(),p.end(),-1);
  sort(edge.begin(),edge.end(),greater<>());
  for(int i=0;i<edge.size();i++){
    ll w,a,b;
    tie(w,a,b) = edge[i];
    if(merge(a,b)){
      cnt++;
      lans+=w;
      if(cnt==n) break;
    }
  }
  lans = n-lans;
  cout << hans*hans-lans*lans << endl;
}  