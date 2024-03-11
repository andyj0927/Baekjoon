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
  int n;
  cin >> n;
  vector <pair<int,int>> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i].se;
    cin >> a[i].fi;
  }
  sort(a.begin(),a.end());
  int ans = 0, end = -1;
  for(int i=0;i<n;i++){
    if(a[i].se>=end){
      ans++;
      end = a[i].fi;
    }
  }
  cout << ans << endl;
}  
