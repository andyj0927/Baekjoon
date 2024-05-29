#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll n;
string st,ed;
int a[10001],d[10001][10],track[10001][10];
ll f(ll pos , ll rot){
  int &re = d[pos][rot];
  if(re!=-1) return re;
  if(pos==n) return re = 0;
  int l = (a[pos]-rot+10)%10;
  int r = (10-a[pos]+rot)%10;
  re = min(f(pos+1,(l+rot)%10)+l,f(pos+1,rot)+r);
  if(re==f(pos+1,(l+rot)%10)+l) track[pos][rot] = l;
  else track[pos][rot] = -1*r;
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> st >> ed;
  for(int i=0;i<n;i++){
    a[i] = (ed[i]-st[i]+10)%10;
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<10;j++) d[i][j] = -1;
  }
  cout << f(0,0) << endl;
  int rotate = 0;
  for(int i=0;i<n;i++){
    if(track[i][rotate]==0) continue;
    cout << i+1 << " " << track[i][rotate] << endl;
    if(track[i][rotate]<0) continue;
    rotate = (rotate+track[i][rotate]+10)%10;
  }
}