#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map <string,int> mp;
vector <int> a[25];
int n;
bool check(int x,int y){
  int both = 0, fi = 0, se = 0;
  for(int i=0;i<n;i++){
    int have_x = 0, have_y = 0;
    for(auto j : a[i]){
      if(j==x) have_x =1;
      if(j==y) have_y = 1;
    }
    if(have_x && have_y) both++;
    else if(have_x) fi++;
    else if(have_y) se++;
  }
  if(both && fi && se) return true;
  return false;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int k;
  cin >> n;
  int cnt = 0;
  for(int i=0;i<n;i++){
    cin >> k;
    for(int j=0;j<k;j++){
      string s;
      cin >> s;
      if(mp.find(s)==mp.end()){
        mp[s] = cnt;
        cnt++;
      }
      a[i].push_back(mp[s]);
    }
  }
  int ans = 1;
  for(int i=0;i<cnt;i++){
    for(int j=i+1;j<cnt;j++){
      if(check(i,j)){
        ans = 0;
        break;
      }
    }
  }
  if(ans) cout << "yes" << endl;
  else cout << "no" << endl;
}