#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

priority_queue<ll> pq;
pll a[200005];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i].fi >> a[i].se;
  }
  sort(a,a+n,greater<>());
  int j=0;
  ll ans = 0;
  for(int i=n;i>=1;i--){
    while(a[j].fi==i && j<n){
      pq.push(a[j].se);
      j++;
    }
    if(!pq.empty()){
      ans+=pq.top();
      pq.pop();
    }
  }
  cout << ans;
}  