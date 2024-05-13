#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector <pii> a(n);
  for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(),a.end());
  vector <int> d(n,1);
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(d[i]<=d[j] && a[i].second>a[j].second){
        d[i] = d[j]+1;
      }
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++) ans = max(ans,d[i]);
  cout << n-ans << endl;

}  