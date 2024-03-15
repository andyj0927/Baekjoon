#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[1000005];
int n;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  ll ans1  = 1e9+5, ans2 = 1e9+5;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++){
    int index = lower_bound(a,a+n,-1*a[i]) - a;
    if(index>0 && i!=index-1 && abs(a[i]+a[index-1])<abs(ans1+ans2)){
      ans1 = a[i];
      ans2 = a[index-1];
    }
    if(index<n && i!=index && abs(a[i]+a[index])<abs(ans1+ans2)){
      ans1 = a[i];
      ans2 = a[index];
    }
    if(index<n-1 && i!=index+1 && abs(a[i]+a[index+1])<abs(ans1+ans2)){
      ans1 = a[i];
      ans2 = a[index+1];
    }
  }
  if(ans1>ans2) swap(ans1,ans2);
  cout << ans1 << " " << ans2;
}  