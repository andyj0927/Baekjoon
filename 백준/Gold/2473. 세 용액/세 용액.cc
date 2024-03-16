#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[5005];
int n;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  ll ans1, ans2 , ans3;
  ans1 =ans2 =ans3 = 1e9+1;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int index = lower_bound(a+j+1,a+n,-a[i]-a[j]) - a ;
      if(index<n && llabs(ans1+ans2+ans3)>llabs(a[i]+a[j]+a[index])){
        ans1 = a[i];
        ans2 = a[j];
        ans3 = a[index];
      }
      if(index-1!=j && llabs(ans1+ans2+ans3)>llabs(a[i]+a[j]+a[index-1])){
        ans1 = a[i];
        ans2 = a[j];
        ans3 = a[index-1];
      }
      if(index<n-1 && llabs(ans1+ans2+ans3)>llabs(a[i]+a[j]+a[index+1])){
        ans1 = a[i];
        ans2 = a[j];
        ans3 = a[index+1];
      }
    }
  }
  cout << ans1 << " "<< ans2 << " "<< ans3;
}  