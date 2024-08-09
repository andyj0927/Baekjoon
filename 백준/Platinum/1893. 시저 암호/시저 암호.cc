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
void solve(){
  vector <int> ans;
  string a,s,p;
  cin >> a >> p >> s;
  vector <int> f = failure(p);
  vector <int> mp(257);
  int idx = 0;
  for(int i : a){
    mp[i]=idx;
    idx++;
  }
  for(int q=0;q<a.size();q++){
    int j=0;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
      while(j>0 && mp[s[i]]!=((mp[p[j]]+q)%a.size())) j = f[j-1];
      if(mp[s[i]]==((mp[p[j]]+q)%a.size())) j++;
      if(j==p.size()){
        cnt++;
        j = f[j-1];
      }
    }
    if(cnt==1) ans.push_back(q);
  }
  if(ans.size()==0){
    cout << "no solution" << endl;
  }
  else if(ans.size()==1){
    cout << "unique: " << ans[0] << endl;
  }
  else{
    cout << "ambiguous: ";
    for(auto i: ans) cout << i << " ";
    cout << endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int repeat;
  cin >> repeat;
  while(repeat--){
    solve();
  }
}