#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[10][10], existcol[10];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;
    for(int j=0;j<n;j++){
      a[i][j] = s[j]-'0';
      existcol[a[i][j]]=1;
    }
  }
  int tot = 0;
  for(int i=1;i<=9;i++) if(existcol[i]) tot++;
  int cnt = 0;
  set <int> s;
  for(int col=1;col<=9;col++){
    int l=100, r = -1, low = 100, high =-1; 
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(a[i][j]==col){
          l = min(l,j);
          r = max(r,j);
          low = min(low,i);
          high = max(high,i);
        }
      }
    }
    if(r==-1) continue;
    
    int check = 1;
    for(int i=low;i<=high;i++){
      for(int j=l;j<=r;j++){
        if(a[i][j]!=col) {s.insert(a[i][j]);}
      }
    }
  }
  cout << tot- s.size();
}