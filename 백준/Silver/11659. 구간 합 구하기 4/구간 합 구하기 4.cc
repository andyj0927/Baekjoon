#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll d[100005];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    ll x;
    cin >> x;
    d[i] = d[i-1]+x;
  }
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    cout << d[y]-d[x-1] << endl;
  }
  
}  
