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
  cin >> n >> k;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  ll ans = 0;
  ll en = 0;
  ll tot = 0;
  for(ll st=0;st<n;st++){
    while(en<n && tot<k+1){
      if(a[en]%2==1) tot+=1;
      ans = max(ans,en-st-tot+1);
      en++;
    }
    if(a[st]%2==1) tot-=1;
  }
  cout << ans;
}  