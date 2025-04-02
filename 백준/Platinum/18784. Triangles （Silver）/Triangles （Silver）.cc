#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;
int n;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  vector <ll> col[20001], row[20001];
  vector <pii> a(n);
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    x+=10000;
    y+=10000;
    a[i] = {x,y};
    col[x].push_back(y);
    row[y].push_back(x);
  }
  vector <ll> pref_col[20001] , pref_row[20001];
  for(int i=0;i<20001;i++){
    if(col[i].empty()) continue;
    sort(col[i].begin(),col[i].end());
    pref_col[i].resize(col[i].size());
    pref_col[i][0] = col[i][0];
    for(int j=1;j<col[i].size();j++){
      pref_col[i][j] = pref_col[i][j-1]+col[i][j];
    }
  }
  for(int i=0;i<20001;i++){
    if(row[i].empty()) continue;
    sort(row[i].begin(),row[i].end());
    pref_row[i].resize(row[i].size());
    pref_row[i][0] = row[i][0];
    for(int j=1;j<row[i].size();j++){
      pref_row[i][j] = pref_row[i][j-1]+row[i][j];
    }
  }
  ll ans = 0;
  for(int i=0;i<n;i++){
    int x = a[i].first , y= a[i].second;
    if(row[y].size()<=1 || col[x].size()<=1) continue;
    int x_idx = lower_bound(row[y].begin(),row[y].end(),x)-row[y].begin();
    int y_idx = lower_bound(col[x].begin(),col[x].end(),y)-col[x].begin();
    ll xval = 0, yval = 0;
    if(x_idx!=0){
      xval+=((x_idx)*x-pref_row[y][x_idx-1]);
    }
    if(x_idx!=row[y].size()-1){
      xval+=(pref_row[y][row[y].size()-1]-pref_row[y][x_idx]-(row[y].size()-1-x_idx)*x);
    }

    if(y_idx!=0){
      yval+=((y_idx)*y-pref_col[x][y_idx-1]);
    }
    if(y_idx!=col[x].size()-1){
      yval+=(pref_col[x][col[x].size()-1]-pref_col[x][y_idx]-(col[x].size()-1-y_idx)*y);
    }
    ans += xval*yval;
    ans%=MAXN;
  }
  cout << ans;
}  