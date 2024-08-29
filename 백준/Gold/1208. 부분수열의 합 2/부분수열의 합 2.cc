#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map <int,int> mp1,mp2;
int a[41];
int n,s,m;
void fdfs(int cur, int sum){
  if(cur==m){
    mp1[sum]++;
    return;
  }
  fdfs(cur+1,sum);
  sum+=a[cur];
  fdfs(cur+1,sum);
  sum-=a[cur];
}
void bdfs(int cur, int sum){
  if(cur==n){
    mp2[sum]++;
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
  cin >> n >> s;
  m = n/2;
  for(int i=0;i<n;i++) cin >> a[i];
  fdfs(0,0);
  bdfs(m,0);
  ll ans=0;
  for(auto [cur, val] : mp1){
    ans+= (ll)mp1[cur]*mp2[s-cur];
  }
  if(s==0) ans--;
  cout << ans << endl;
}