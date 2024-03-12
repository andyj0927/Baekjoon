#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int const MAXN = 1e6+5;
pll a[MAXN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i].fi;
    cin >> a[i].se;
  }
  sort(a,a+n);
  ll st = a[0].fi, ed = a[0].se, ans=0;
  for(int i=1;i<n;i++){
    if(ed<a[i].fi){
      ans+=(ed-st);
      st = a[i].fi;
      ed = a[i].se;
    }
    else{
      ed = max(ed,a[i].se);
    }
  }
  ans+=(ed-st);
  cout << ans;

}  