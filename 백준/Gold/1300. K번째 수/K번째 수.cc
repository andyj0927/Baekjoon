#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll n,k;
ll a[10001];
ll solve(ll cur){
  ll re = 0;
  for(int i=1;i<=n;i++){
    ll low = 1, high = n, cal=0;
    while(low<=high){
      ll midval = (low+high)/2;
      if(midval*i<=cur) {low=midval+1; cal = midval;}
      else{
        high = midval-1;
      }
    }
    re+=cal;
  }
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  ll l=1, h =n*n , ans;
  while(l<=h){
    ll mid = (l+h)/2;
    if(solve(mid)>=k){
      h = mid-1;
      ans = mid;
    }
    else{
      l = mid+1;
    }
  }
  cout << ans;
}