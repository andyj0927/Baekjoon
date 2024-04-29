#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector <tuple<ll,int,int>> edge;
ll n;
vector <int> p(100005,-1);
pair<tuple<ll,ll,ll>,int> a[100005];
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
bool comparesecond(const pair<tuple<ll,int,int>,int> &a,const pair<tuple<ll,int,int>,int> &b){
  return get<1>(a.first) < get<1>(b.first);
}
bool comparethird(const pair<tuple<ll,int,int>,int> &a,const pair<tuple<ll,int,int>,int> &b){
  return get<2>(a.first) < get<2>(b.first);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x,y,z;
    cin >> x >> y >> z;
    a[i] = {make_tuple(x,y,z),i+1};
  }
  sort(a,a+n);
  for(int i=1;i<n;i++){
    int x,y,z, bx,by,bz;
    tie(x,y,z) = a[i].fi;
    tie(bx,by,bz) = a[i-1].fi;
    edge.push_back(make_tuple(x-bx,a[i].second,a[i-1].second));
  }
  sort(a,a+n,comparesecond);
  for(int i=1;i<n;i++){
    int x,y,z, bx,by,bz;
    tie(x,y,z) = a[i].fi;
    tie(bx,by,bz) = a[i-1].fi;
    edge.push_back(make_tuple(y-by,a[i].second,a[i-1].second));
  }
  sort(a,a+n,comparethird);
  for(int i=1;i<n;i++){
    int x,y,z, bx,by,bz;
    tie(x,y,z) = a[i].fi;
    tie(bx,by,bz) = a[i-1].fi;
    edge.push_back(make_tuple(z-bz,a[i].second,a[i-1].second));
  }
  sort(edge.begin(),edge.end());
  ll ans=0, cnt=0;
  for(int i=0;i<edge.size();i++){
    int x,y,w;
    tie(w,x,y) = edge[i];
    if(merge(x,y)){
      ans+=w;
      cnt++;
      if(cnt==n-1){
        break;
      }
    }
  }
  cout << ans << endl;
}  