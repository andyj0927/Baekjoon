#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e5+5;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n,m;
  cin >> n >> m;
  vector <ll> mod(m,0);
  vector <ll> s(n+1,0);
  for(int i=1;i<=n;i++){
    cin >> s[i];
    s[i]+=s[i-1];
  }
  for(int i=0;i<=n;i++){
    mod[s[i]%m]+=1;
  }
  ll ans = 0;
  for(int i=0;i<m;i++){
    ans+=(mod[i])*(mod[i]-1)/2;
  }
  cout << ans;
} 