#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> failure(string &s){
  vector <int> f(s.size(),0);
  int j=0;
  for(int i=1;i<s.size();i++){
    while(j>0 && s[i]!=s[j]) j = f[j-1];
    if(s[i]==s[j]) f[i] = ++j;
  }
  return f;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(true){
    string s;
    cin >> s;
    if(s==".") break;
    vector <int> f = failure(s);
    int idx = f[s.size()-1];
    int ans = s.size()-idx;
    if(s.size()%ans!=0) cout << 1 << endl;
    else{
      cout << s.size()/ans << endl;
    }
  }
}