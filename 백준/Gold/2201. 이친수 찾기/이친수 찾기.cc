#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll k;
ll d[102][2];
ll f(ll index, ll val){
  ll &re = d[index][val];
  if(re!=-1) return re;
  if(index==1) return re = 1; 
  re = f(index-1,0);
  if(val==0) re+=f(index-1,1);
  if(re>k) re = k+1;
  return re;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k;
  for(int i=0;i<=101;i++){
    for(int j=0;j<=1;j++) d[i][j] = -1;
  }
  ll tot = f(101,0), ans = 0;
  for(int i=1;i<=100;i++){
    k-=f(i,1);
    if(k<=0){
      k+=f(i,1);
      ans = i;
      break;
    }
  }
  cout << 1;
  ll be = 1;
  for(int i=ans-1;i>=1;i--){
    if(be==1){
      cout << 0;
      be = 0;
      continue;
    }
    if(k>f(i,0)){
      cout << 1;
      be = 1;
      k-=f(i,0);
    }
    else{
      cout << 0;
      be = 0;
    }
  }
}