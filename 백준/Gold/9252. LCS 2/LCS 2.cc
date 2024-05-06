#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;

int dp[1002][1002];
char d[1002][1002];
pii pre[1002][1002];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s1,s2;
  cin >> s1 >> s2;
  s1 = "@"+s1;
  s2 ="@"+s2;
  for(int i=1;i<s1.length();i++){
    for(int j=1;j<s2.length();j++){
      if(s1[i]==s2[j]){
        dp[i][j] = dp[i-1][j-1]+1;
        pre[i][j] = {i-1,j-1};
        d[i][j]=s1[i];
      }
      else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        if(dp[i-1][j]>dp[i][j-1]){
          pre[i][j] = {i-1,j};
        }
        else{
          pre[i][j] = {i,j-1};
        }
      }
    }
  }
  cout << dp[s1.length()-1][s2.length()-1]<<endl;
  vector <char> ans;
  int a=s1.length()-1, b= s2.length()-1;
  while(a!=0 || b!=0){
    if(d[a][b]!='\0') ans.push_back(d[a][b]);
    pii tt = pre[a][b];
    a = tt.first;
    b= tt.second;
  }
  for(int i=ans.size()-1;i>=0;i--) cout <<ans[i];
}  