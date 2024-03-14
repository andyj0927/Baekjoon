#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,k;
  cin>>n >> k;
  ll cnt = 0ll, digit = 0ll, t = 1ll;
  while(cnt<k){
    digit++;
    cnt += 9*t*digit;
    t*=10;
  }
  ll ans = t-1-(cnt-k)/digit;
  if(ans>n){
    cout << -1;
    return 0;
  }
  ll tot = (cnt-k)%digit;
  while(tot--){
    ans/=10;
  }
  cout << ans%10;

}  