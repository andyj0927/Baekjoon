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
  while(true){
    ll a,b;
    cin >> a >> b;
    if(a==0 && b==0) return 0;
    if(b>a) swap(a,b);
    ll turn = 1, choose=-1;
    while(b!=0){
      ll n = a/b;
      if(n>1 && choose==-1) choose = turn;
      a = a%b;
      swap(a,b);
      turn = !turn;
    }
    if(choose!=-1){
      if(choose) cout << "A wins" << endl;
      else cout << "B wins" << endl;
    }
    else{
      if(turn) cout << "B wins" << endl;
      else cout << "A wins" << endl;
    }
  }
}