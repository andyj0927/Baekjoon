#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int vis[100005];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  ll ans = 0;
  ll st = 0;
  for(ll en=0;en<n;en++){
    vis[a[en]]++;
    while(vis[a[en]]>1){
      vis[a[st]]--;
      st++;
    }
    ans+=(en-st+1);
  }
  cout << ans;
}  