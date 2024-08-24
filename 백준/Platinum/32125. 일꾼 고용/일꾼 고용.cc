#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
vector <ll> a[1000001];
void solve(){
  ll n ,k;
  cin >> n >> k;
  vector <ll> c(n+1,0);
  for(int i=0;i<=2*n;i++){
    a[i].clear();
  }
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    if(x==2) x= -1;
    c[i] = x;
  }
  vector <ll> w(n+1,0);
  for(int i=1;i<=n;i++){
    cin >> w[i];
    w[i]*=c[i];
    w[i]+=w[i-1];
  }
  for(int i=1;i<=n;i++){
    c[i]+=c[i-1];
  }
  for(int i =0;i<=n;i++){
    a[c[i]+n].push_back(w[i]);
  }
  ll ans = 0;
  for(int i=0;i<=2*n;i++){
    if(a[i].size()<=1) continue;
    sort(a[i].begin(),a[i].end());
    for(int j=0;j<a[i].size();j++){
      auto l = lower_bound(a[i].begin(),a[i].end(),a[i][j]-k);
      auto h = upper_bound(a[i].begin(),a[i].end(),a[i][j]+k);
      ans+=(h-l-1);
    }
  }
  cout << ans/2 << endl;

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