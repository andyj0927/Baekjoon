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
  int n;
  cin >> n;
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int i=0;i<n*n;i++){
    ll x;
    cin >> x;
    pq.push(x);
    if(pq.size()>n) pq.pop();
  }
  cout << pq.top();
}  