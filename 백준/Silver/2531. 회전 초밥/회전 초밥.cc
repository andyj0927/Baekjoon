#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,d,k,c;
  cin >> n >> d >> k >> c;
  vector <int> a(n),many(d+1,0);
  for(int i=0;i<n;i++) cin >> a[i];
  ll ans = 0;
  many[c]++;
  for(int i=0;i<k;i++){
    many[a[i]]++;
  }
  for(int i=1;i<=d;i++){
    if(many[i]) ans++;
  }
  ll tot = ans;
  for(int i=0;i<=n-1;i++){
    many[a[i]]--;
    if(a[i]==c && many[a[i]]==0){
      many[a[i]]= 1;
    }
    if(many[a[i]]==0) tot--;
    many[a[(i+k)%n]]++;
    if(many[a[(i+k)%n]]==1) tot++;
    ans = max(ans,tot);
  }
  cout << ans;
}  