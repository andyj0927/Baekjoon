#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set <pll> s;
map <ll,ll> mp;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  for(int i=0;i<n;i++){
    ll x,y;
    cin >> x >> y;
    s.insert({y,x});
    mp[x] = y;
  }
  ll m;
  cin >> m;
  for(int i=0;i<m;i++){
    string st;
    ll x,y;
    cin >> st;
    if(st=="add"){
      cin >> x >> y;
      s.insert({y,x});
      mp[x] = y;
    }
    if(st=="recommend"){
      cin >> x;
      if(x==1){
        cout << (*s.rbegin()).second << endl;
      }
      else{
        cout << (*s.begin()).second << endl;
      }
    }
    if(st=="solved"){
      cin >> x;
      if(s.find({mp[x],x})==s.end()) continue;
      s.erase(s.find({mp[x],x}));
    }
  }
}  