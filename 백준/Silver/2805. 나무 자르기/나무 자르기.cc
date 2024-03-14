#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[1000005];
ll n,m;

bool f(ll x){
  ll cnt = 0;
  for(int i=0;i<n;i++){
    cnt+=max(a[i]-x,0ll);
  }
  if(cnt>=m) return true;
  else return false;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for(int i=0;i<n;i++) cin >> a[i];
  ll l=1, h =1e9 , ans = 0;
  while(l<=h){
    ll mid = (l+h)/2;
    if(f(mid)){
      l = mid+1;
      ans = mid;
    }
    else{
      h = mid-1;
    }
  }
  cout << ans;
}  