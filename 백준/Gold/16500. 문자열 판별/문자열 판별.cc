#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e6;
int n,m;
string s;
string a[101];
int d[102];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  m = s.length();
  d[0] = 1;
  for(int i=1;i<=m;i++){
    if(d[i-1]!=1) continue;
    for(int j=0;j<n;j++){
      if(a[j].length()+i-1>m) continue;
      if(s.substr(i-1,a[j].length())==a[j]) d[i-1+a[j].length()] = 1;
    }
  }
  cout << d[m];
}