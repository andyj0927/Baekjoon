#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll n,m,k, check =1;
ll d[201][101][101];
ll f(ll pos , ll usen , ll usem){
  ll &re = d[pos][usen][usem];
  if(re!=-1) return re;
  if(pos==0) return re = 1;
  re = 0;
  if(usen>=1) re+=f(pos-1,usen-1,usem);
  if(usem>=1) re+=f(pos-1,usen,usem-1);
  if(re>k) re = k+1;
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for(int i=0;i<=n+m;i++){
    for(int j=0;j<=n;j++){
      for(int x=0;x<=m;x++){
        d[i][j][x] = -1;
      }
    }
  }
  ll tot = f(n+m,n,m);
  if(tot<k){
    cout << -1;
    exit(0);
  }
  int curn = n , curm = m;
  for(int i=n+m;i>=1;i--){
    if(curn==0){
      cout << "z";
    }
    else if(curm ==0){
      cout << "a";
    }
    else if(f(i-1,curn-1,curm)<k){
      cout << 'z';
      k-=f(i-1,curn-1,curm);
      curm -=1;
    }
    else{
      curn-=1;
      cout << 'a';
    }
  }
}