#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int d[1000005] , pre[1000005];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  pre[1] = 0;
  d[1] = 0;
  for(int i=2;i<=n;i++){
    d[i] = d[i-1]+1;
    pre[i] = i-1;
    if(i%2==0){
      if(d[i] > d[i/2]+1){
        d[i] = d[i/2]+1;
        pre[i] = i/2;
      }
    }
    if(i%3==0){
      if(d[i] > d[i/3]+1){
        d[i] = d[i/3]+1;
        pre[i] = i/3;
      }
    }
  }
  cout << d[n] << endl;
  while(pre[n]!=0){
    cout << n << " ";
    n = pre[n];
  }
  cout << 1;

  
}  