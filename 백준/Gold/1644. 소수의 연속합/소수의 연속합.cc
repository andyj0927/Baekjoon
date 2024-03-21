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
  ll n,s;
  cin >> n;
  vector <int> prime, a(n+1,0);
  for(int i=2;i<=sqrt(n);i++){
    if(a[i]==1)continue;
    else{
      for(int j=2;j*i<=n;j++){
        a[j*i] = 1;
      }
    }
  }
  int ans = 0;
  for(int i=2;i<=n;i++){
    if(a[i]==0) prime.push_back(i);
  }
  int en = 0,tot = 0;
  for(int st = 0;st<prime.size();st++){
    while(en<prime.size() && tot<n){
      tot+=prime[en];
      en++;
    }
    if(tot==n){
      ans++;
    }
    tot-=prime[st];
  }
  cout << ans;
}  