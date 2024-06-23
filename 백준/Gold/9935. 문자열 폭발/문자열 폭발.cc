#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 5e5+2;
int vis[1502][1502];
char board[1501][1501];
int dx[4]={0,1,0,-1};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector <char> v;
  string s, ans;
  cin >> s >> ans;
  for(int i=0;i<s.length();i++){
    v.push_back(s[i]);
    if(ans.length()<=v.size()){
      bool flag = 1;
      for(int j=0;j<ans.length();j++){
        if(ans[j]!=v[v.size()-ans.length()+j]){
          flag = 0;
          break;
        }
      }
      if(flag==1){
        for(int j=0;j<ans.length();j++) v.pop_back();
      }
    }
  }
  if(v.size()==0) cout << "FRULA";
  else for(int i=0;i<v.size();i++) cout << v[i];
}