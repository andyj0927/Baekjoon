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
  vector <int> ans;
  string s, p;
  getline(cin,s);
  getline(cin,p);
  vector <int> f = failure(p);
  int j=0;
  for(int i=0;i<s.size();i++){
    while(j>0 && s[i]!=p[j]) j = f[j-1];
    if(s[i]==p[j]) j++;
    if(j==p.size()){
      ans.push_back(i-p.size()+1);
      j = f[j-1];
    }
  }
  cout << ans.size() << endl;
  for(auto i : ans) cout << i+1 << " ";

}