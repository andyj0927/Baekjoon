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
  cin>>n;
  int a[10] = {};
  int cnt = 0;
  for(int i=9;i>=0;i--){
    a[i] = 1;
    do{
      if(cnt==n){
        for(int i=0;i<10;i++){
          if(a[i]){
            cout << 9-i;
          }
        }
        cout << endl;
        return 0;
      }
      cnt++;
    }while(next_permutation(a,a+10));
  }
  cout << -1;

}  