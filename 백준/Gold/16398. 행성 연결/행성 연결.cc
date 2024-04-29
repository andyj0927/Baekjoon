#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector <tuple<ll,int,int>> edge;
int n;
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
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ll x;
      cin >> x;
      if(i<j) edge.push_back(make_tuple(x,i,j));
    }
  }
  sort(edge.begin(),edge.end());
  ll cnt = 0, ans = 0;
  for(int i=0;i<edge.size();i++){
    ll w,a,b;
    tie(w,a,b) = edge[i];
    if(merge(a,b)){
      cnt++;
      ans+=w;
      if(cnt==n-1) break;
    }
  }
  cout << ans << endl;
}  