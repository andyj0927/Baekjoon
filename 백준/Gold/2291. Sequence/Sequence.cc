#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll n,m,k;
ll d[11][221][221];
ll f(ll cur , ll tot, ll pastval){ 
  ll &re = d[cur][tot][pastval];
  if(re!=-1) return re;
  if(cur==n && tot==m) return re = 1;
  if(cur==n) return re = 0;
  re = 0;
  for(int i=pastval;i+tot<=m;i++){
    re+=f(cur+1,tot+i,i);
    if(re>k) re = k+1;
  }
  return re;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for(int i=0;i<=10;i++){
    for(int j=0;j<=m;j++){
      for(int x=1;x<=m;x++){
        d[i][j][x] = -1;
      }
    }
  }
  ll ans = f(0,0,1);
  ll curtot = 0, curvalue = 1, pastvalue = 1 , cnt = 0;
  for(int i=0;i<n;i++){
    curvalue = pastvalue;
    while(cnt<k){
      cnt+=f(i+1,curtot+curvalue,curvalue);
      curvalue++;
    }
    curvalue--;
    cnt-=f(i+1,curtot+curvalue,curvalue);
    pastvalue = curvalue;
    curtot+=pastvalue;
    cout << curvalue<< " ";
  }
}