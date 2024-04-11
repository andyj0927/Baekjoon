#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int lc[26], rc[26];

void pre(int cur){
  cout << char(cur+'A');
  if(lc[cur]!=0)pre(lc[cur]);
  if(rc[cur]!=0)pre(rc[cur]);
}
void mid(int cur){
  if(lc[cur]!=0)mid(lc[cur]);
  cout << char(cur+'A');
  if(rc[cur]!=0)mid(rc[cur]);
}
void last(int cur){
  if(lc[cur]!=0)last(lc[cur]);
  if(rc[cur]!=0)last(rc[cur]);
  cout << char(cur+'A');
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    char m , l ,c;
    cin >> m >> l >> c;
    if(l!='.')lc[m-'A'] = l-'A';
    if(c!='.')rc[m-'A'] = c-'A';
  }
  pre(0);
  cout << endl;
  mid(0);
  cout << endl;
  last(0);
}  