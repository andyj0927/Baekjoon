#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll one[92] , zero[92];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  one[1] = 1;
  zero[1] = 0;
  for (int i=2;i<=n;i++){
    one[i] = zero[i-1];
    zero[i] = zero[i-1]+one[i-1];
  }
  cout << one[n]+zero[n];

}  
