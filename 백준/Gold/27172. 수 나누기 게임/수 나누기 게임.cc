#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e15;

int check[1000001], ans[1000001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  vector <ll> x(n);
  for(int i=0;i<n;i++) {cin >> x[i]; check[x[i]]=1;}
  for(int i=0;i<n;i++){
    for(int j=x[i]*2;j<=1000000;j+=x[i]){
      if(check[j]) {ans[x[i]]++; ans[j]--;}
    }
  }
  for(int i=0;i<n;i++) cout << ans[x[i]] << " ";

}  