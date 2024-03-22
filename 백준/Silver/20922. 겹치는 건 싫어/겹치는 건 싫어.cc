#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e6+5;
int vis[MAXN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,k;
  cin >> n >> k;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int en = 0;
  int ans = 0;
  for(int st=0;st<n;st++){
    while(en<n && vis[a[en]]<=k-1){
      vis[a[en]]++;
      en++;
    }
    ans = max(ans,en-st);
    vis[a[st]]--;
  }
  cout << ans;
}  