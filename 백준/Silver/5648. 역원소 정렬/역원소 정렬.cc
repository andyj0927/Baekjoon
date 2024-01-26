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
  cout.tie(0);
  int n;
  cin >> n;
  vector <ll> a(n);
  for(int i=0;i<n;i++){
    string s , t;
    cin >> s;
    t.append(s);
    for(int i=0;i<s.length();i++){
      t[s.length()-1-i] = s[i];
    }
    a[i] = stoll(t); 
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    cout << a[i] << endl;
  }

}  