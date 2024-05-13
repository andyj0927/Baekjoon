#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
int a[10][10];
vector <pii> ch;

void f(int x){
  if(x==ch.size()){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++) cout << a[i][j] << " ";
      cout << endl;
    }
    exit(0);
  }
  auto [i,j] = ch[x];
  vector <int> okay(10,0);
  for(int k=0;k<9;k++){
    okay[a[i][k]]=1;
    okay[a[k][j]]=1;
  }
  int nx = (i/3) , ny = (j/3);
  nx *=3;
  ny *=3;
  for(int ni=nx;ni<nx+3;ni++){
    for(int nj=ny;nj<ny+3;nj++){
      okay[a[ni][nj]]=1;
    }
  }
  for(int aa=1;aa<10;aa++){
    if(okay[aa]==0){
      a[i][j]=aa;
      f(x+1);
      a[i][j] =0;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++) {cin >> a[i][j]; if(a[i][j]==0) ch.push_back({i,j});}
  }
  f(0);

}  