#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll d[102];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  d[1] = 1;
  d[2] = 1;
  d[3] = 1;
  d[4] = 2;
  d[5] = 2;
  for(int i=6;i<=100;i++){
    d[i] = d[i-1]+d[i-5];
  }
  while(t--){
    int x;
    cin >> x;
    cout << d[x] << endl;
  }


}  
