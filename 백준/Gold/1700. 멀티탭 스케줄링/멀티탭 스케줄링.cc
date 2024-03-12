#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  set <int> s;
  vector <int> a(k);
  int ans = 0;
  for(int i=0;i<k;i++) cin >> a[i];
  for(int i=0;i<k;i++){
    if(s.find(a[i])!=s.end()) continue;
    if(s.size()<n){s.insert(a[i]); continue;}
    set <int> del;
    del =s;
    for(int j=i+1;j<k;j++){
      if(del.size()==1) break;
      if(del.find(a[j])==s.end()) continue;
      del.erase(a[j]);
    }
    s.erase(*del.begin());
    s.insert(a[i]);
    ans++;
  }
  cout << ans;

}  