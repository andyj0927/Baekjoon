#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool compare(const pair<int,int> &a, const pair<int,int> &b){
  if( a.se == b.se ){
    return a.fi < b.fi;
  }
  return a.se < b.se;
}

void solve(){
  int n,m;
  cin >> n >> m;
  vector <int> a(n),b(m);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    a[i] = x;
  }
  for(int i=0;i<m;i++){
    int x;
    cin >> x;
    b[i] = x;
  }
  int ans = 0;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int x = 0, y = 0;
  while(true){
    if(a[x]>b[y]){
      ans = ans + (n-x);
      y++;
    }
    else{
      x++;
    }
    if(x==n || y==m){
      cout << ans << endl;
      return;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}  
