#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
int idx[7][2];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<7;i++){
    for(int j=0;j<2;j++) idx[i][j] = -1;
  }
  idx[0][0] = 0;
  idx[0][1] = 0;
  vector <ll> a(n+1);
  for(int i=1;i<=n;i++) cin >> a[i];
  for(int i=1;i<=n;i++){
    a[i]=a[i-1]+a[i];
    if(idx[a[i]%7][0]==-1){
      idx[a[i]%7][0] = i;
    }
    idx[a[i]%7][1] = i;
  }
  int ans = 0;
  for(int i=0;i<7;i++){
    ans = max(ans,idx[i][1]-idx[i][0]);
  }
  cout << ans;
}  