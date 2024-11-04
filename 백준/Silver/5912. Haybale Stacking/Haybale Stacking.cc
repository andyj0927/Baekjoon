#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
int idx[7][2];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,k;
  cin >> n >> k;
  vector <int> a(n,0);
  while(k--){
    int st,ed;
    cin >> st >> ed;
    st--;
    ed--;
    a[st]++;
    if(ed!=n-1) a[ed+1]--;
  }
  for(int i=1;i<n;i++){
    a[i]+=a[i-1];
  }
  sort(a.begin(),a.end());
  cout << a[n/2];
}  