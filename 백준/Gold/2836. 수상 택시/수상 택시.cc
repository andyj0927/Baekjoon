#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m;
  cin >> n >> m;
  vector <pll> a;
  for(int i=0;i<n;i++){
    ll x,y;
    cin >> x >> y;
    if(x>y){
      a.push_back({y,x});
    }
  }
  sort(a.begin(),a.end());
  ll st = -1, ed = -1;
  for(int i=0;i<a.size();i++){
    if(ed<a[i].first){
      m+=(ed-st)*2;
      st = a[i].first;
      ed = a[i].second;
    }
    else{
      ed = max(ed,a[i].second);
    }
  }
  m+=(ed-st)*2;
  cout << m;
}