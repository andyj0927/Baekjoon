#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e6+5;
ll a[MAXN];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,s;
  cin >> n >> s;
  for(int i=0;i<n;i++) cin>> a[i];
  int en = 0;
  int mn = n+5;
  ll tot = 0;
  for(int st = 0;st<n;st++){
    while(en<n && tot<s){
      tot+=a[en];
      en++;
    }
    if(en==n){
      if(tot<s) break;
    }
    mn = min(mn,en-st);
    tot-=a[st];
  }
  if(mn==n+5) mn=0;
  cout << mn;
}  