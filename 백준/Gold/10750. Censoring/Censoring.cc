#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
ll g[2001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s,t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  vector <char> a;
  for(int i=0;i<n;i++){
    a.push_back(s[i]);
    if(a.size()>=m){
      int flag =1;
      for(int j=0;j<m;j++){
        if(a[a.size()-m+j]!=t[j]){
          flag = 0;
          break;
        }
      }
      if(flag){
        for(int j=0;j<m;j++) a.pop_back();
      }
    }
  }
  for(int i=0;i<a.size();i++) cout<<a[i];
}