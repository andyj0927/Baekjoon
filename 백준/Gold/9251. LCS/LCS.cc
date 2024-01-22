#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s1;
  string s2;
  int a[1002][1002]={0,};
  cin >> s1 >> s2;
  int n = s1.length(), m =s2.length();
  s1 = "0"+s1;
  s2= "0" + s2;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s1[i]==s2[j]){
        a[i][j] = a[i-1][j-1]+1;
      }
      a[i][j] = max({a[i][j],a[i][j-1],a[i-1][j]});
    }
  }
  cout << a[n][m];
}