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
  vector <pii> a(n);
  for(int i=0;i<n;i++){
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    a[i].fi = 100*a1+a2;
    a[i].se = 100*b1+b2;
  }
  sort(a.begin(),a.end());
  int be = 301, af = 0, cnt = 1;
  for(int i=0;i<n;i++){
    if(a[i].fi<=be){
      af = max(af,a[i].se);
    }
    if(af>1130){
      cout << cnt;
      return 0;
    }
    if(a[i].fi>be){
      be = af;
      if(be>=a[i].fi){
        cnt++;
        af = max(af,a[i].se);
      }
      else{
        cout << 0;
        return 0;
      }
    }
  }
  if(af>1130) cout << cnt;
  else cout << 0;

}  
