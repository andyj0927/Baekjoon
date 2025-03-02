#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e5+1;
ll n, m,r;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> r;
  vector <ll> c(n),rev(r);
  vector <ll> pre_r(r+1,0);
  vector <pll> v(m);
  for(int i=0;i<n;i++) cin >> c[i];
  for(int i=0;i<m;i++){
    int q,p;
    cin >> q >> p;
    v[i].first = p;
    v[i].second = q;
  }
  for(int i=0;i<r;i++) cin >> rev[i];
  sort(c.begin(),c.end(),greater<ll>());
  sort(rev.begin(),rev.end(),greater<ll>());
  sort(v.begin(),v.end(),greater<pll>());
  for(int i=0;i<r;i++){
    pre_r[i+1]=pre_r[i]+rev[i];
  }
  ll j = 0, ans=pre_r[min(n,r)], cnt=0;
  for(int i=1;i<=n;i++){
    int cur = c[i-1];
    while(j<m && cur>v[j].second){
      cnt+=v[j].second*v[j].first;
      cur-=v[j].second;
      j++;
    }
    if(j<m){
      cnt+=v[j].first*cur;
      v[j].second-=cur;
    }
    ans = max(ans,cnt+pre_r[min(n-i,r)]);
  }
  cout << ans;

}  