#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 5e5+2;

ll n,a[21][21];

ll f(ll left, ll right, ll low, ll high, ll dir){
  int good = 0, bad = 0;
  vector <int> goodrow(n,0), badrow(n,0),goodcol(n,0),badcol(n,0);
  for(int i=low;i<high;i++){
    for(int j=left;j<right;j++){
      if(a[i][j]==2) {good++; goodrow[i] = 1; goodcol[j]=1;}
      if(a[i][j]==1) {bad++; badrow[i] = 1; badcol[j] = 1;}
    }
  }
  if(left==right || low==high) return 1ll;
  if(good==0) return -1;
  if(good==1 && bad ==0) return 1ll;
  ll ans = 0ll;
  if(dir==0){
    for(int i=low;i<high;i++){
      if(badrow[i] && !goodrow[i]){
        ll f1 = f(left,right,low,i,1);
        ll f2 = f(left,right,i+1,high,1);
        if(f1==-1 || f2==-1) continue;
        ans+=f1*f2;
      }
    }
  }
  if(dir==1){
    for(int i=left;i<right;i++){
      if(badcol[i] && !goodcol[i]){
        ll f1 = f(left,i,low,high,0);
        ll f2 = f(i+1,right,low,high,0);
        if(f1==-1 || f2==-1) continue;
        ans+=f1*f2;
      }
    }
  }
  if(ans==0) return -1ll;
  else return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cin >> a[i][j];
  }
  ll f1 = f(0,n,0,n,1);
  ll f2 = f(0,n,0,n,0);
  if(f1==-1 && f2==-1) cout << -1;
  else if(f1==-1) cout << f2;
  else if(f2==-1) cout << f1;
  else cout << f1+f2;
}