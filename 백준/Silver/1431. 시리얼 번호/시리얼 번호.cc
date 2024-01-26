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
    int anum = 0 , bnum = 0;
    for(int i=0;i<a.length();i++){
      if(a[i]-'0'>=0 && a[i]-'0'<=9) anum+=(a[i]-'0');
    }
    for(int i=0;i<b.length();i++){
      if(b[i]-'0'>=0 && b[i]-'0'<=9) bnum+=(b[i]-'0');
    }
    if(anum==bnum){
      return a<b;
    }
    return anum < bnum;
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
  for(int i=0;i<n;i++){
    cout << a[i] << endl;
  }
}  
