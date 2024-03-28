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
  int t;
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    while(k--){
      char op;
      int n;
      cin >> op >> n;
      if(op=='D'){
        if(!s.empty()){
          if(n==-1){
            auto it = s.begin();
            s.erase(it);
          }
          else{
            auto it = s.end();
            it--;
            s.erase(it);
          }
        }
      }
      else{
        s.insert(n);
      }
    }
    if(s.empty()){
      cout << "EMPTY" << endl;
    }
    else{
      auto it1 = s.begin();
      auto it2 = s.end();
      it2--;
      cout << *it2 <<" " << *it1 << endl;
    }
    s.clear();
  }
}  