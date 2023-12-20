#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[8][8]={};
int vis[8][8];
vector <pii> v;
vector <int> tq;
int n,m;
void up(int x, int y){
    while(a[x][y]!=6 && x>=0){
      vis[x][y]++;
      x--;
    }
}
void re_up(int x, int y){
    while(a[x][y]!=6 && x>=0){
      vis[x][y]--;
      x--;
    }
}
void down(int x, int y){
    while(a[x][y]!=6 && x<n){
      vis[x][y]++;
      x++;
    }
}
void re_down(int x, int y){
    while(a[x][y]!=6 && x<n){
      vis[x][y]--;
      x++;
    }
}
void right(int x, int y){
    while(a[x][y]!=6 && y<m){
      vis[x][y]++;
      y++;
    }
}
void re_right(int x, int y){
    while(a[x][y]!=6 && y<m){
      vis[x][y]--;
      y++;
    }
}
void left(int x, int y){
    while(a[x][y]!=6 && y>=0){
      vis[x][y]++;
      y--;
    }
}
void re_left(int x, int y){
    while(a[x][y]!=6 && y>=0){
      vis[x][y]--;
      y--;
    }
}

void f(int t){
    if(t==v.size()){
      int sum = 0;
      for(int i=0;i<v.size();i++){
        if(vis[v[i].fi][v[i].se]==0){
          vis[v[i].fi][v[i].se]++;
        }
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(vis[i][j])sum++;
        }
      }
      tq.push_back(sum);
      return;
    }
    int x = v[t].fi , y = v[t].se;
    if(a[x][y]==1){
      up(x,y);
      f(t+1);
      re_up(x,y);
      down(x,y);
      f(t+1);
      re_down(x,y);
      right(x,y);
      f(t+1);
      re_right(x,y);
      left(x,y);
      f(t+1);
      re_left(x,y);
    }
    else if(a[x][y]==2){
      up(x,y);
      down(x,y);
      f(t+1);
      re_up(x,y);
      re_down(x,y);
      left(x,y);
      right(x,y);
      f(t+1);
      re_left(x,y);
      re_right(x,y);
    }
    else if(a[x][y]==3){
      up(x,y);
      right(x,y);
      f(t+1);
      re_up(x,y);
      re_right(x,y);
      //
      up(x,y);
      left(x,y);
      f(t+1);
      re_up(x,y);
      re_left(x,y);
      //
      down(x,y);
      right(x,y);
      f(t+1);
      re_down(x,y);
      re_right(x,y);
      //
      down(x,y);
      left(x,y);
      f(t+1);
      re_down(x,y);
      re_left(x,y);
    }
    else if(a[x][y]==4){
      up(x,y);
      right(x,y);
      left(x,y);
      f(t+1);
      re_up(x,y);
      re_right(x,y);
      re_left(x,y);
      //
      down(x,y);
      right(x,y);
      left(x,y);
      f(t+1);
      re_down(x,y);
      re_right(x,y);
      re_left(x,y);
      //
      up(x,y);
      down(x,y);
      left(x,y);
      f(t+1);
      re_up(x,y);
      re_down(x,y);
      re_left(x,y);
      //
      up(x,y);
      right(x,y);
      down(x,y);
      f(t+1);
      re_up(x,y);
      re_right(x,y);
      re_down(x,y);
    }
    else if(a[x][y]==5){
      up(x,y);
      right(x,y);
      down(x,y);
      left(x,y);
      f(t+1);
      re_up(x,y);
      re_right(x,y);
      re_down(x,y);
      re_left(x,y);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int cnt=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> a[i][j];
        if(a[i][j]>=1 && a[i][j]<=5){
          v.push_back({i,j});
        }
        if(a[i][j]==6){
          cnt++;
        }
      }
    }
    if(v.size()==0){
      cout << n*m-cnt;
      return 0;
    }
    f(0);
    int q = *max_element(tq.begin(),tq.end());
    cout << n*m-q-cnt;
}