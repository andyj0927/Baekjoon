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
  int ans=-1005, tot = 0;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(i==0) ans = x;
    else{
      if(tot>0) x+=tot;
      ans = max(ans,x);
    }
    tot = max(0,x);
  }
  cout << ans;

}  
