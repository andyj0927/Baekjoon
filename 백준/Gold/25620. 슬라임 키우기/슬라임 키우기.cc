#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
ll n,q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  vector <ll> a(n+1);
  set <pll> s;
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++){
    auto it = s.lower_bound({a[i],-1});
    if(it!=s.end() && it->first == a[i]){
      int val = (it->second);
      s.insert({a[i],val+1});
      s.erase({a[i],val});
    }
    else{
      s.insert({a[i],1});
    }
  }
  while(q--){
    ll x,y;
    cin >> x >> y;
    if(y==1) continue;
    vector <pll> ins;
    for(auto it = s.begin();it!=s.end();){
      auto [val,cur] = *it;
      if(val>x) break;
      it = s.erase(it);
      ins.push_back({val,cur});
    }
    for(auto [val,cur] : ins){
      auto it = s.lower_bound({val*y,-1});
      if(it!=s.end() && it->first==val*y){
        int t = (it->second);
        s.insert({val*y,t+cur});
        s.erase({val*y,t});
      }
      else{
        s.insert({val*y,cur});
      }
    }
  }
  for(auto [val,cur] : s){
    for(int i=0;i<cur;i++) cout << val <<" ";
  }
}