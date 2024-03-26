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
  string s, f;
  getline(cin,s);
  getline(cin,f);
  int ans = 0;
  for(int i=0;i<s.length();i++){
    int check = 1;
    for(int j=0;j<f.length();j++){
      if(i+j>=s.length() || s[i+j]!=f[j]){
        check = 0;
        break;
      }
    }
    if(check){
      ans++;
      i = i+f.length()-1;
    }
  }
  cout << ans;
} 