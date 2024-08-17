#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

void solve(){
  int n;
  cin >> n;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  ll sum = 0;
  for(int i=0;i<n;i++) sum+=a[i];
  vector <int> candidate;
  if(sum==0){
    cout << 0 << endl;
    return;
  }
  for(int i=1;i<=sum;i++){
    if(sum%i==0) candidate.push_back(i);
  }
  for(int i=0;i<candidate.size();i++){
    int cur = candidate[i];
    int tot  = 0, flag = 1,ans=0;
    for(int j=0;j<n;j++){
      if(a[j]+tot>cur){
        flag = 0;
        break;
      }
      tot+=a[j];
      if(tot==cur){
        ans++;
        tot = 0;
      }
    }
    if(flag==1){
      cout << n-ans << endl;
      return;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int repeat;
  cin >> repeat;
  while(repeat--){
    solve();
  }
}