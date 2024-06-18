#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e6+5;
int n;
int a[MAXN], before[MAXN];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1;i<=n;i++) cin >> a[i];
  a[n+1] = 1e9+1;
  a[0] = -1*a[n+1];
  vector <int> d(n+1,0);
  int output = 0;
  for(int i=1;i<=n;i++){
    d[i] = n+1;
  }
  for(int i=1;i<=n;i++){
    int l = 0, h = i-1, ans = 0;
    while(l<=h){
      int mid = (l+h)/2;
      if(a[d[mid]]<a[i]){
        ans = mid;
        l = mid+1;
      }
      else{
        h= mid-1;
      }
    }
    before[i] = d[ans];
    if(a[d[ans+1]]>a[i]) d[ans+1] = i;
    output = max(output,ans+1);
  }
  cout << output << endl;
  ll realans = d[output];
  vector <int> aa;
  while(realans!=0){
    aa.push_back(a[realans]);
    realans = before[realans];
  }
  for(int i=aa.size()-1;i>=0;i--) cout << aa[i] << " ";

}