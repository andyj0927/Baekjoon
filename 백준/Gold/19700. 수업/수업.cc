#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

multiset <int> s;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n; 
  vector <pii> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i].fi >> a[i].se;
  }
  sort(a.begin(),a.end(),greater<pii>());
  for(int i=0;i<n;i++){
    int x = a[i].se-1;
    auto it = s.lower_bound(-x);
    if(it==s.end()){
      s.insert(-1);
    }
    else{
      int y = *it;
      s.erase(it);
      s.insert(y-1);
    }
  }
  cout << s.size();
}  