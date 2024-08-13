#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e5;
const ll MOD = 1e9+7;
bool compare(const pll &a, const pll &b){
  if(a.second==b.second){
    return a.first<b.first;
  }
  return a.second<b.second;
}
int dp[2501];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int n;
  n = s.length();
  vector <pii> a;
  for(int i=0;i<n;i++){
    int st = i, ed = i;
    while(st>=0 && ed<n){
      if(s[st]==s[ed]){
        a.push_back({st+1,ed+1});
      }
      else break;
      st--;
      ed++;
    }
  }
  for(int i=0;i<n-1;i++){
    int st = i, ed = i+1;
    while(st>=0 && ed<n){
      if(s[st]==s[ed]){
        a.push_back({st+1,ed+1});
      }
      else break;
      st--;
      ed++;
    }
  }
  sort(a.begin(),a.end(),compare);
  for(int i=0;i<=n;i++){
    dp[i] = i;
  }
  for(int i=0;i<a.size();i++){
    dp[a[i].second] = min(dp[a[i].first-1]+1,dp[a[i].second]);
  }
  cout << dp[n];
}