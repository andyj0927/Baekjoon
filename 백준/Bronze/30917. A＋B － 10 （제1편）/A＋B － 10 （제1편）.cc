#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e6+5;
int vis[MAXN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a=1, b=1, ans;
  while(true){
    cout << "? A " << a << endl;
    cout << flush; 
    cin >> ans;
    if(ans){
      break;
    }
    a++;
  }
  while(true){
    cout << "? B " << b << endl;
    cout << flush; 
    cin >> ans;
    if(ans){
      break;
    }
    b++;
  }
  cout << "! " << a+b << endl;
  cout << flush;
}  