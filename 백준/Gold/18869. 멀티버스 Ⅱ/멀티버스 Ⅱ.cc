#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[105][10005];
int m,n;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> n;
  for(int i=0;i<m;i++){
    vector <ll> b;
    for(int j=0;j<n;j++){
      cin >> a[i][j];
      b.push_back(a[i][j]);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int j=0;j<n;j++){
      a[i][j] = lower_bound(b.begin(),b.end(),a[i][j])-b.begin();
    }
  }
  ll ans = 0;

  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      bool check = true;
      for(int k=0;k<n;k++){
        if(a[i][k]!=a[j][k]){
          check = false;
          break;
        }
      }
      if(check) ans++;
    }
  }
  cout << ans;
}  