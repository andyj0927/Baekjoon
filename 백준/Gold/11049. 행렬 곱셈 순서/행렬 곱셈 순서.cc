#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
int k,t;
int r[501], c[501];
ll d[501][501];
ll f(int st, int ed){
  ll &re = d[st][ed];
  if(re!=MAXN) return re;
  if(st==ed) return re = 0;
  for(int i=st;i<=ed-1;i++){
    re = min(re,f(st,i)+f(i+1,ed)+r[st]*c[i]*c[ed]);
  }
  return re;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k;
  for(int i=1;i<=k;i++) {cin >> r[i]; cin >> c[i];}
  for(int i=1;i<=k;i++){
    for(int j=1;j<=k;j++) d[i][j] = MAXN;
  }
  cout << f(1,k);
}