#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> p(10005,-1);
int v,e;
tuple<ll,int,int> tree[100005];
int find(int n){
  if(p[n]<0){
    return n;
  }
  p[n] = find(p[n]);
  return p[n];
}
bool merge(int a, int b){
  a = find(a);
  b = find(b);
  if(a==b) return false;
  if(p[a]==p[b]) p[a]--;
  if(p[a]<=p[b]) p[b] = a;
  else p[a] = b;
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int v,e,a,b;
  ll c;
  cin >> v >> e;
  for(int i=0;i<e;i++){
    cin >> a >> b >> c;
    tree[i] = make_tuple(c,a,b);
  }
  sort(tree,tree+e);
  ll ans = 0, cnt = 0;
  for(int i=0;i<e;i++){
    tie(a,b,c) = tree[i];
    if(merge(b,c)){
      ans+= a;
      cnt++;
      if(cnt==v-1) break;
    }
  }
  cout << ans << endl;
}  