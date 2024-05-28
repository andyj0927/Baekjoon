#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e6;
int d[31][30001];
int check[30001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n;
  vector <int> a(n);
  for(int i=1;i<=n;i++) cin >> a[i];
  d[0][15000] = 1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=30000;j++){
      if(d[i-1][j]){
        d[i][j] = 1;
        d[i][j+a[i]] = 1;
        d[i][j-a[i]] = 1;
        check[j] = 1;
        check[j+a[i]] = 1;
        check[j-a[i]] = 1;
      }
    }
  }
  cin >> m;
  while(m--){
    int x;
    cin >> x;
    if(x<=30000 && check[x+15000]) cout << "Y" << " ";
    else cout << "N" << " ";
  }
}