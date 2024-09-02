#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int a[1001];
int dp[1001][1001][2];
int f(int st,int ed, int state){
  int &re = dp[st][ed][state];
  if(re!=-1) return re;
  if(st==ed){
    if(state) return re = a[st];
    else return re = 0;
  }
  if(state){
    re = max(f(st+1,ed,0)+a[st],f(st,ed-1,0)+a[ed]);
  }
  else{
    re = min(f(st+1,ed,1),f(st,ed-1,1));
  }
  return re;
}
void solve(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<2;k++) dp[i][j][k] = -1;
    }
  }
  int x = f(0,n-1,1);
  cout << x <<  endl;
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