#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> failure(vector <int> &s){
  vector <int> f(s.size(),0);
  int j=0;
  for(int i=1;i<s.size();i++){
    while(j>0 && s[i]!=s[j]) j = f[j-1];
    if(s[i]==s[j]) f[i] = ++j;
  }
  return f;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector <int> a(n),b(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int j=0;j<n;j++) cin >> b[j];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  vector <int> sa(2*n),sb(n);
  for(int i=0;i<n;i++){
    sa[i] = (a[(i+1)%n]-a[i]+360000)%360000;
    sb[i] = (b[(i+1)%n]-b[i]+360000)%360000;
  }
  for(int i=n;i<2*n;i++) sa[i] = sa[i-n];
  vector <int> f = failure(sb);
  int j=0;
  for(int i=0;i<2*n;i++){
    while(j>0 && sa[i]!=sb[j]) j = f[j-1];
    if(sa[i]==sb[j]) j++;
    if(j==n){
      cout << "possible" ;
      return 0;
    }
  }
  cout << "impossible";
  
}