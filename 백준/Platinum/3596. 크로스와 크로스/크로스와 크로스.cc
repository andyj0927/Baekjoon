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
  int n;
  cin >> n;
  g[0] = 0;
  g[1] = 1;
  g[2] = 1;
  g[3] = 1;
  for(int i=4;i<=n;i++){
    vector <int> a;
    for(int j=1;j<=i;j++){
      int l = j-2 , h = j+2;
      int cur = 0;
      if(1<l){
        cur^=g[l-1];
      }
      if(h<n){
        cur^=g[i-h];
      }
      a.push_back(cur);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int mex = 0;
    for(int i=0;i<a.size();i++){
      if(a[i]!=mex){
        break;
      }
      mex++;
    }
    g[i] = mex;
  }
  if(g[n]) cout << 1;
  else cout << 2;
}