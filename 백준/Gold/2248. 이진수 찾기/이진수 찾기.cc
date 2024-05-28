#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll n,l,k;
ll d[32][32];

ll f(int x, int y){
  ll &re = d[x][y];
  if(re!=0) return re;
  if(x==0) return re = 1;
  re = f(x-1,y);
  if(y>=1) re+=f(x-1,y-1);
  return re;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> l >> k;
  ll tot = f(n,l);
  for(int i=n;i>=1;i--){
    if(d[i-1][l]<k){
      k-=d[i-1][l];
      l-=1;
      cout << 1;
    }
    else {cout << 0;}
  }
}