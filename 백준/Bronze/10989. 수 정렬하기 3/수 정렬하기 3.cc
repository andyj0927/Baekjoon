#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a[10001];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    a[x]++;
  }
  for(int i=1;i<=10000;i++){
    for(int j=0;j<a[i];j++) cout << i << endl;
  }
}  