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
  vector <ll> a(n);
  for(int i=0;i<n;i++){
    ll s;
    cin >> s;
    a[i] = s;
  }
  sort(a.begin(),a.end());
  ll mn = a[0];
  ll mx_num = 1;
  ll be = a[0];
  ll cnt = 1;
  for(int i=1;i<n;i++){
    if(be==a[i]) cnt++;
    else{
      if(cnt>mx_num){
        mn = be;
        mx_num = cnt;
      }
      cnt = 1;
      be = a[i];
    }
  }
  if(cnt>mx_num) mn = be;
  cout << mn;

}  
