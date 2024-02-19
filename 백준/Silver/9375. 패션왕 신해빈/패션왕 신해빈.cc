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
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string a,b;
    map <string , int> mp;
    for(int i=0;i<n;i++){
      cin >> a >> b;
      mp[b]++;
    }
    int ans = 1;
    for(auto i : mp){ 
      int val = i.second+1;
      ans*=val;
    }
    ans-=1;
    cout << ans << endl;
  }

}  