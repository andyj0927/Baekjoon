#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int d[45][2];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  d[0][0] = 1, d[0][1] = 0, d[1][0] = 0, d[1][1] = 1;
  for(int i=2;i<=40;i++){
    d[i][0] = d[i-2][0]+d[i-1][0];
    d[i][1] = d[i-2][1]+d[i-1][1];
  }
  while(t--){
    int n;
    cin >> n;
    cout << d[n][0] << " " << d[n][1] << endl;
  }

}  
