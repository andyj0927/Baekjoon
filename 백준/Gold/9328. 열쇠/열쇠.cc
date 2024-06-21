#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 5e5+2;
int went[105][105], vis[105][105], cango[26];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
string s[105];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int h, w;
    cin >> h >> w;
    for(int i=0;i<=h+1;i++){
      s[i] = string(w+2,'.');
    }
    for(int i=1;i<=h;i++){
      string row;
      cin >> row;
      for(int j=1;j<=w;j++){
        s[i][j] = row[j-1];
      }
    }
    fill(cango,cango+26,-1);
    vector <pii> door[26];
    for(int i=0;i<=h+1;i++){
      for(int j=0;j<=w+1;j++){
        went[i][j] = -1;
        vis[i][j] = -1;
        if(s[i][j]>='A' && s[i][j]<='Z'){
          door[s[i][j]-'A'].push_back({i,j});
        }
      }
    }
    string have;
    cin >> have;
    if(have[0]!='0') for(int i=0;i<have.length();i++) cango[have[i]-'a']=1;
    queue <pii> q;
    for(int i=0;i<=h+1;i++){
      for(int j : {0,w+1}){
        q.push({i,j});
        vis[i][j] =1;
        went[i][j] = 1;
      }
    }
    for(int i=1;i<=w;i++){
      for(int j : {0,h+1}){
        q.push({j,i});
        vis[j][i] =1;
        went[j][i] = 1;
      }
    }
    int ans=0;
    while(!q.empty()){
      auto cur = q.front();
      q.pop();
      if(s[cur.first][cur.second]=='$') ans++;
      for(int i=0;i<4;i++){
        int nx = cur.first+dx[i];
        int ny = cur.second+dy[i];
        if(nx<0 || nx>h+1 || ny<0 || ny>w+1) continue;
        if(vis[nx][ny]!=-1) continue;
        if(s[nx][ny]=='*') continue;
        if(s[nx][ny]>='A' && s[nx][ny]<='Z'){
          if(cango[s[nx][ny]-'A']==-1){
            went[nx][ny] = 1;
            continue;
          }
        }
        vis[nx][ny] = 1;
        q.push({nx,ny});
        if(s[nx][ny]>='a' && s[nx][ny]<='z'){
          cango[s[nx][ny]-'a']=1;
          for(auto nxt : door[s[nx][ny]-'a']){
            if(vis[nxt.first][nxt.second]!=-1) continue;
            if(went[nxt.first][nxt.second]==1){
              q.push({nxt.first,nxt.second});
              vis[nxt.first][nxt.second];
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
}