#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll n,k;
ll d[52][104][2]; // 0->-50, 50 -> 0, 100 -> 50
ll pow2[52]; 
ll f(ll cur, ll cnt, ll check){
  ll &re = d[cur][cnt][check];
  if(re!=-1) return re;
  if(cur==n+1 && (check||cnt!=50)) return re =1;
  else if(cur==n+1) return re =0;
  re = 0;
  re+= f(cur+1,cnt+1, check);
  re+=f(cur+1,cnt-1 , check || (cnt==50 ? 1: 0));
  return re;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  ll curcnt = 50;
  for(int i=1;i<=n+1;i++){
    for(int j=0;j<=101;j++){
      for(int ii=0;ii<2;ii++) d[i][j][ii] = -1;
    }
  }
  ll tot = f(1,50,0);
  k++;
  pow2[0] = 1;
  for(int i=1;i<=n;i++){
    pow2[i] = pow2[i-1]*2;
  }
  if(tot<k){
    cout << -1;
    exit(0);
  }
  ll curcheck = 0;
  for(ll i=1;i<=n;i++){
    ll strc;
    if(curcheck){
      strc = f(i+1,curcnt+1,1);
    }
    else{
      strc = f(i+1,curcnt+1,0);
    }
    if(k>strc){
      cout << ")";
      if(curcnt==50) curcheck = 1;
      curcnt--;
      k-=strc;
    }
    else{
      cout << "(";
      curcnt++;
    }
  }
}