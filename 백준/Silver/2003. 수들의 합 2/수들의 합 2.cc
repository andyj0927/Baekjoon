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
  ll n,m;
  cin >> n >> m;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int ans = 0;
  int en = 0;
  ll tot = 0;
  for(int st=0;st<n;st++){
    while(en<n && tot<m){
      tot+=a[en];
      en++;
    }
    if(tot==m) ans++;
    tot-=a[st];
  }

  cout << ans;
}  