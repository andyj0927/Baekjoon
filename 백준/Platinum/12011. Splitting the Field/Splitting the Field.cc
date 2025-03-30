#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e5+1;
ll n,m;
vector <pll> arr;
ll f(){
  sort(arr.begin() , arr.end());

  auto cal = [](pair<ll,ll> a, ll b) -> pair <ll,ll> {
    return {min(a.first,b),max(a.second,b)};
  };
  vector <pll> pref(n), suf(n);
  pref[0] = {arr[0].second,arr[0].second};
  suf[n-1] = {arr[n-1].second,arr[n-1].second};
  for(int i=1;i<n;i++){
    pref[i] = cal(pref[i-1],arr[i].second);
  }
  for(int i=n-2;i>=0;i--){
    suf[i] = cal(suf[i+1],arr[i].second);
  }
  ll tot = (arr[n-1].first-arr[0].first)*(pref[n-1].second-pref[n-1].first);
  ll sol = tot;
  for(int i=0;i<n-1;i++){
    if(arr[i].first!=arr[i+1].first){
      ll a1 = (pref[i].second-pref[i].first)*(arr[i].first-arr[0].first);
      ll a2 = (suf[i+1].second-suf[i+1].first)*(arr[n-1].first-arr[i+1].first);
      sol = min(sol,a1+a2);
    }
  }
  return tot-sol;

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  arr.resize(n);
  for(int i=0;i<n;i++){
    cin >> arr[i].first >> arr[i].second;
  }
  ll ans = 0;
  ans = max(ans,f());
  for(int i=0;i<n;i++){
    swap(arr[i].first,arr[i].second);
  }
  ans = max(ans,f());
  cout << ans;
}  