#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[502][502];
pair<int,int> d[7][4]={
{{0,0},{0,1},{0,2},{0,3}},
{{0,0},{0,1},{1,0},{1,1}},
{{0,0},{1,0},{2,0},{2,1}},
{{0,0},{1,0},{1,1},{2,1}},
{{0,0},{0,1},{1,1},{0,2}},
{{0,0},{1,0},{1,1},{1,2}},
{{0,0},{0,1},{1,1},{1,2}}
};

pair <int,int> rotate(int x,int y, int k){
  while(k--){
    int t = x;
    x  = y;
    y = -1*t;
  }
  return {x,y};
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,m, ans = 0;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<7;k++){
        for(int rot=0;rot<4;rot++){
          int tot = 0;
          int check = 1;
          for(int tet = 0;tet<4;tet++){
            auto newp =d[k][tet];
            newp = rotate(newp.first,newp.second,rot);
            int nx = i+newp.first;
            int ny = j+newp.second;
            if(nx<0||ny<0||nx>=n||ny>=m){
              check = 0;
              break;
            }
            tot+=a[nx][ny];
          }
          if(check){
            ans = max(ans,tot);
          }
        }
      }
    }
  }
  cout << ans;
}  
