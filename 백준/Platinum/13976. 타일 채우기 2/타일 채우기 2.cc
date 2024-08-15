#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

ll n;
typedef vector <vector <ll>> matrix;
matrix matmul(matrix &a, matrix &b){
  matrix result = {{0,0},{0,0}};
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<2;k++){
        ll temp=(a[i][k]*b[k][j])%MOD;
        temp+=MOD;
        temp%=MOD;
        result[i][j] = (result[i][j]+temp)%MOD;
      }
    }
  }
  return result;
}
matrix matpower(matrix &a, ll t){
  matrix result = {{1,0},{0,1}};
  while(t){
    if(t%2){
      result = matmul(result,a);
    }
    a = matmul(a,a);
    t/=2;
  }
  return result;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  if(n%2==1){
    cout << 0;
    return 0;
  }
  matrix a = {{4,-1},{1,0}};
  matrix f = {{3,0},{1,0}};
  ll t = (n-2)/2;
  a= matpower(a,t);
  matrix ans= matmul(a,f);
  cout << ans[0][0];
}