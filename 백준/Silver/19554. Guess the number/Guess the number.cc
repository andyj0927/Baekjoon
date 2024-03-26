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
  ll n;
  cin >> n;
  ll l = 1, h = n;
  while(true){
    ll mid = (l+h)/2;
    cout << "? " << mid << endl;
    cout << flush;
    int ans;
    cin >> ans;
    if(ans==0){
      cout << "= " << mid << endl;
      cout << flush;
      break;
    }
    else if(ans==1){
      h = mid-1;
    }
    else{
      l = mid+1;
    }
  }
}  