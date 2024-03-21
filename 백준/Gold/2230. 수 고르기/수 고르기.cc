#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e6+5;
ll a[MAXN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) cin>> a[i];
  sort(a,a+n);
  int en = 0;
  ll mn = 2e9+5;
  for(int st = 0;st<n;st++){
    while(en<n && a[en]-a[st]<m){
      en++;
    }
    if(en==n) break;
    mn = min(mn,a[en]-a[st]);
  }
  cout << mn;
}  