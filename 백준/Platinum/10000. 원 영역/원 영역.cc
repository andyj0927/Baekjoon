#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+5;
bool compare(const pll &a, const pll &b){
  if(a.first==b.first){
    return a.second>b.second;
  }
  return a.first<b.first;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector <pll> a(n+1);
  for(int i=0;i<n;i++){
    ll x,r;
    cin >> x >> r;
    a[i].first = x-r;
    a[i].second = x+r;
  }
  a[n].first = MAXN;
  a[n].second = MAXN;
  sort(a.begin(),a.end(),compare);
  stack <int> q;
  vector <ll> circle(n+1);
  for(int i=0;i<=n;i++){
    circle[i] = a[i].first;
  }
  for(int i=0;i<=n;i++){
    while(!q.empty() && a[q.top()].second<=a[i].first ){
      int cur = q.top();
      q.pop();
      if(!q.empty() && circle[q.top()]==a[cur].first){
        circle[q.top()] = a[cur].second;
      }
    }
    q.push(i);
  }
  ll ans = n+1;
  for(int i=0;i<n;i++){
    if(circle[i]==a[i].second) ans++;
  }
  cout << ans;
}