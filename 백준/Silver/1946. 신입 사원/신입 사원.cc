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
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector <pii> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    int top = a[0].se , ans= 1;
    for(int i=1;i<n;i++){
      if(top>a[i].se){
        top = a[i].se;
        ans++;
      }
    }
    cout << ans << endl;
  }

}  
