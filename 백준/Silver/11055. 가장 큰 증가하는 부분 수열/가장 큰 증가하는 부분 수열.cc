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
  vector <int> a(n), d(n,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(a[i]>a[j] && d[i]<d[j]){
        d[i] = d[j];
      }
    }
    d[i]+=a[i];
  }
  cout << *max_element(d.begin(),d.end());


}  
