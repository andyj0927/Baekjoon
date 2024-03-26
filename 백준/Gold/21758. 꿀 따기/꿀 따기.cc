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
  ll n;
  cin >> n;
  vector <ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  ll ans1 = 0, ans2 = 0,sum=0;
  for(int i=1;i<n;i++) ans1+=a[i];
  ll tot = 0, two = 0;
  for(int i=n-1;i>=1;i--){
    tot+=a[i];
    if(i==n-1) two = tot-2*a[i];
    two = max(two,tot-2*a[i]);
  }
  for(int i=0;i<n-1;i++) ans2+=a[i];
  tot = 0;
  ll three = 0;
  for(int i=0;i<n-1;i++){
    tot+=a[i];
    if(i==0) three = tot-2*a[i];
    three = max(three,tot-2*a[i]);
  }
  for(int i=0;i<n;i++) sum+=a[i];
  sum-=a[0];
  sum-=a[n-1];
  ll mx = 0;
  for(int i=1;i<n-1;i++){
    mx = max(mx,a[i]);
  }
  cout << max({ans1 + two,ans2+three ,sum+mx});

}  