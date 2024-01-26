#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b){
  return a.fi > b.fi;
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  ll c;
  cin >> n >> c;
  vector <pair<ll,ll>> a;
  for(int i=0;i<n;i++){
    ll x;
    cin >> x;
    int check = 0;
    for(auto &t : a){
      if(t.second==x){
        t.first++;
        check=1;
      }
    }
    if(!check) a.push_back({1ll,x});
  }
  stable_sort(a.begin(),a.end(),compare);
  for(int i=0;i<a.size();i++){
    for(int j=0;j<a[i].fi;j++) cout << a[i].se << endl;
  }
}  
