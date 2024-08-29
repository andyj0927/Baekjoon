#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <ll> f,b;
ll a[31];
ll n,c,m;
void fdfs(int cur, ll sum){
  if(cur==m){
    f.push_back(sum);
    return;
  }
  fdfs(cur+1,sum);
  sum+=a[cur];
  fdfs(cur+1,sum);
  sum-=a[cur];
}
void bdfs(int cur, ll sum){
  if(cur==n){
    b.push_back(sum);
    return;
  }
  bdfs(cur+1,sum);
  sum+=a[cur];
  bdfs(cur+1,sum);
  sum-=a[cur];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> c;
  m = n/2;
  for(int i=0;i<n;i++) cin >> a[i];
  fdfs(0,0);
  bdfs(m,0);
  ll ans=0;
  sort(f.begin(),f.end());
  sort(b.begin(),b.end());
  for(int i=0;i<f.size();i++){
    ll idx = upper_bound(b.begin(),b.end(),c-f[i])-b.begin();
    ans+= idx;
  }
  cout << ans;
}