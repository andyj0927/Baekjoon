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
  ll n,m,x;
  cin >> n >> m >> x;
  vector <ll> a(m+1,0);
  for(int i=1;i<=m;i++) cin >> a[i];
  for(int i=1;i<m;i++){
    a[i]-=a[m];
  }
  x-=(n*a[m]);
  for(int i=1;i<m;i++){
    ll na =min(x/a[i],n);
    x-=na*a[i];
    n-=na;
    cout << na << " ";
  }
  cout << n << " ";
}  