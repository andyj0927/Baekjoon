#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,l;
  cin >> n >> l;
  vector <ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  deque <ll> dq;
  for(int i=0;i<n;i++){
    while(!dq.empty() && a[dq.back()]>a[i]){
      dq.pop_back();
    }
    dq.push_back(i);
    while(dq.front()<i-l+1) dq.pop_front();
    cout << a[dq.front()] << " ";
  }
  
}