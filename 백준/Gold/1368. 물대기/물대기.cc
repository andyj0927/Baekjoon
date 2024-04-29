#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector <tuple <ll,int,int>> edge;
vector <int> p(301,-1);
ll ans = 0, cnt = 0;
int find(int cur){
  if(p[cur]<=0) return cur;
  p[cur] = find(p[cur]);
  return p[cur];
}

void merge(int a,int b,int w){
  a = find(a);
  b = find(b);
  if(a==b) return;
  if(p[a]==0 && p[b]==0) return;
  if(p[a]==0 || p[b]==0){
    cnt+=max(abs(p[b]),abs(p[a]));
    p[a] = 0;
    p[b] = 0;
    ans+=w;
    return;
  }
  p[a]+=p[b];
  p[b] = a;
  ans+=w;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  ll w;
  for(int i=1;i<=n;i++){
    cin >> w;
    edge.push_back(make_tuple(w,i,i));
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> w;
      if(i<j) edge.push_back(make_tuple(w,i,j));
    }
  }
  sort(edge.begin(),edge.end()); 
  for(int i=0;i<edge.size();i++){
    int a,b;
    tie(w,a,b) = edge[i];
    if(a==b){
      a = find(a);
      if(p[a]!=0){
        cnt+=abs(p[a]);
        ans+=w;
        p[a] = 0;
        if(cnt==n) break;
      }
      continue;
    }
    merge(a,b,w);
    if(cnt==n) break;
  }


  cout << ans << endl;

}  