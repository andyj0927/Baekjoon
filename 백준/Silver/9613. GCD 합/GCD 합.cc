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
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector <int> a(n);
    ll sum = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        sum+=(ll)gcd(a[i],a[j]);
      }
    }
    cout << sum << endl;
  }
}  