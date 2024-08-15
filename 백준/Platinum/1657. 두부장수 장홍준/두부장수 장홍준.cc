#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

int dp[225][1<<14];
int a[15][15];
int level[5][5]={{10,8,7,5,1},{8,6,4,3,1},{7,4,3,2,1},{5,3,2,2,1},{1,1,1,1,0}};
int n,m;

int f(int cur, int state){
  if(cur==n*m && state==0) return 0;
  if(cur>=n*m) return -MAXN;
  int &re = dp[cur][state];
  if(re!=-1) return re;
  re = 0;
  if(state&1){
    return re = f(cur+1,state>>1);
  }
  re = max(re,f(cur+1,state>>1));
  if(cur/m<n-1) re = max(re,f(cur+1,(state>>1)|(1<<m-1))+level[a[cur/m][cur%m]][a[cur/m+1][cur%m]]);
  if(cur<n*m-1&& cur%m<m-1 && m!=1 && (state&2)==0){
    re = max(re,f(cur+2,state>>2)+level[a[cur/m][cur%m]][a[cur/m][cur%m+1]]);
  }
  return re;

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp,-1,sizeof(dp));
  cin >> n >> m;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<m;j++){
      if(s[j]=='A') a[i][j] = 0;
      if(s[j]=='B') a[i][j] = 1;
      if(s[j]=='C') a[i][j] = 2;
      if(s[j]=='D') a[i][j] = 3;
      if(s[j]=='F') a[i][j] = 4;
    }
  }
  cout << f(0,0);
  
}