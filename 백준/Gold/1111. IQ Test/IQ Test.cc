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
  ll n;
  cin >> n;
  vector <ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  if(n<=1){
    cout << "A" << endl;
    return 0;
  }
  else if(n==2 && a[1]!=a[0]){
    cout << "A" << endl;
    return 0;
  }
  ll d;
  if(a[1]==a[0]){
    d = 1;
  }
  else{
    d = (a[2]-a[1])/(a[1]-a[0]);
    if(d*(a[1]-a[0])!=(a[2]-a[1])){
      cout << "B" << endl;
      return 0;
  }
  }
  ll b = a[1]-a[0]*d;
  for(int i=1;i<n;i++){
    if(a[i]!=(a[i-1]*d+b)){
      cout << "B" << endl;
      return 0;
    }
  }
  cout << a[n-1]*d+b << endl;

}  