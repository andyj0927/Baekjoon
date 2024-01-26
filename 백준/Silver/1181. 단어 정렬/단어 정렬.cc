#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool compare(const string &a, const string &b){
  if( a.length() == b.length() ){
    return a<b;
  }
  return a.length() < b.length();
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <string> a(n);
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    a[i] = s;
  }
  sort(a.begin(),a.end(),compare);
  string be;
  for(int i=0;i<n;i++){
    if(i==0){
      be = a[i];
    }
    else{
      if(be.compare(a[i])==0){
        continue;
      }
      be = a[i];
    }
    cout << a[i] << endl;
  }
}  
