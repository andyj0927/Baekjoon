#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e5+5;
ll d[100005], gas[100005];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  for(int i=1;i<n;i++) {cin >> d[i]; d[i]+=d[i-1];}
  for(int i=0;i<n;i++) cin>> gas[i];
  ll st = 0, ans=0;
  while(st!=n-1){
    ll nxt = st+1;
    while(gas[nxt]>=gas[st] && nxt<n-1) nxt+=1;
    ans+= (d[nxt]-d[st])*gas[st];
    st=nxt;
  }
  cout << ans;
}