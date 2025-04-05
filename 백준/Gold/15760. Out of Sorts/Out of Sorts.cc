#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector <int> b= a;
  sort(b.begin(),b.end());
  int ans = 0;
  for(int i=0;i<n;i++){
    int idx = upper_bound(b.begin(),b.end(),a[i])-b.begin()-1;
    if(i-idx) ans = max(i-idx,ans);
  }
  cout << ans+1;
}  