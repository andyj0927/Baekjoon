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
  vector <int> a(n);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    a[i] = x;
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    cout << a[i] << endl;
  }
}  