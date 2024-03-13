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
  ll t;
  cin >> t;
  while(t--){
    int x,y;
    cin >> x >> y;
    int dis = y-x;
    ll l=1, h = y-x,ans=1e9;
    while(l<=h){
      ll mid = (l+h)/2;
      if(mid%2==1){
        if((mid/2)*(mid/2+1)+mid/2+1>=dis){
          ans = min(mid,ans);
          h = mid-1;
        }
        else{
          l = mid+1;
        }
      }
      else{
        if((mid/2)*(mid/2+1)>=dis){
          ans = min(mid,ans);
          h = mid-1;
        }
        else{
          l = mid+1;
        }
      }
    }
    cout << ans << endl;
  }

}  