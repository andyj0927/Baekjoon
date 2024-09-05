#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[1000][1000];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cin >> a[i][j];
  }
  ll ans1 = 0,ans2=0;
  for(int i=0;i<n;i++){
    ll cnt1=0,cnt2=0;
    for(int j=0;j<n;j++){
      if(j%2==0) cnt1+=a[i][j];
      else cnt2+=a[i][j];
    }
    ans1+=max(cnt1,cnt2);
  }
  for(int i=0;i<n;i++){
    ll cnt1=0,cnt2=0;
    for(int j=0;j<n;j++){
      if(j%2==0) cnt1+=a[j][i];
      else cnt2+=a[j][i];
    }
    ans2+=max(cnt1,cnt2);
  }
  cout << max(ans1,ans2);
}