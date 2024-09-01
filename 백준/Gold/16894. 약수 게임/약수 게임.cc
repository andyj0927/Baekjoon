#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  ll cnt = 0;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
      n/=i;
      cnt++;
    }
  }
  if(n>1) cnt++;
  if(cnt==2){
    cout << "cubelover";
  }
  else cout << "koosaga";
}