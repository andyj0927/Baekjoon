#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <ll> two;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for(int i=0;i<n;i++) cin>> a[i];
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      two.push_back(a[i]+a[j]);
    }
  }
  sort(two.begin(),two.end());
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<n;j++){
      if(binary_search(two.begin(),two.end(),a[i]-a[j])){
        cout << a[i];
        return 0;
      }
    }
  }
}  