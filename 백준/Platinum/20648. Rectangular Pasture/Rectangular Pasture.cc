#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
int arr[2501][2501];
ll cal(int le,int ri, int l, int h){
  return arr[h][ri]-arr[l-1][ri]-arr[h][le-1]+arr[l-1][le-1];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector <pii> a(n);
  vector <int> x(n),y(n);
  for(int i=0;i<n;i++){
    cin >> a[i].fi >> a[i].se;
    x[i] = a[i].fi;
    y[i] = a[i].se;
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  x.erase(unique(x.begin(),x.end()),x.end());
  y.erase(unique(y.begin(),y.end()),y.end());
  for(int i=0;i<n;i++){
    a[i].fi=lower_bound(x.begin(),x.end(),a[i].fi)-x.begin()+1;
    a[i].se=lower_bound(y.begin(),y.end(),a[i].se)-y.begin()+1;
    arr[a[i].fi][a[i].se] = 1;
  }
  for(int i=1;i<=x.size();i++){
    for(int j=1;j<=y.size();j++){
      arr[i][j]+=(arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]);
    }
  }
  sort(a.begin(),a.end());
  ll ans = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int low = a[i].fi, high = a[j].fi;
      int le = min(a[i].se,a[j].se), ri = max(a[i].se,a[j].se);
      ll lval = cal(1,le,low,high);
      ll rval = cal(ri,n,low,high);
      ans+=lval*rval;
    }
  }
  cout << ans+n+1 << endl;
}  