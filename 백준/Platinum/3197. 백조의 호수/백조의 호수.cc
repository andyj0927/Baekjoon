#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int vis[1501][1501], visbaek[1501][1501];
char board[1501][1501];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int r,c;
bool OOB(int x, int y){
    if(x<0 || x>=r || y<0 || y>=c) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    queue <pii> q, baek;
    int flag = 1;
    for(int i=0;i<r;i++){
        string s;
        cin >> s;
        for(int j=0;j<c;j++){
            if(s[j]=='.'){
                q.push({i,j});
                vis[i][j] = 1;
                board[i][j] = '.';
            }
            else if(s[j]=='L'){
                board[i][j] = '.';
                q.push({i,j});
                vis[i][j] = 1;
                if(flag){
                    baek.push({i,j});
                    visbaek[i][j] = 1;
                    flag = 0;
                }
                else{
                    board[i][j] = 'L';
                }
            }
            else{
                board[i][j] = 'X';
            }
        }
    }
    int ans = 1;
    while(true){
        queue <pii> nq;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(OOB(nx,ny)|| vis[nx][ny]) continue;
                nq.push({nx,ny});
                vis[nx][ny] = 1;
                if(board[nx][ny]=='X') nq.push({nx,ny});
            }
        }
        while(!nq.empty()){
            auto cur = nq.front();
            nq.pop();
            board[cur.first][cur.second] = '.';
            q.push({cur.first,cur.second});
        }
        while(!baek.empty()){
            auto cur = baek.front();
            baek.pop();
            for(int i=0;i<4;i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(OOB(nx,ny)|| visbaek[nx][ny]) continue;
                if(board[nx][ny]=='X') {nq.push({nx,ny}); visbaek[nx][ny] = 1;}
                else if(board[nx][ny]=='L'){
                    cout << ans;
                    return 0;
                }
                else{
                    baek.push({nx,ny});
                    visbaek[nx][ny] = 1;
                }
            }
        }
        while(!nq.empty()){
            auto cur = nq.front();
            nq.pop();
            baek.push({cur.first,cur.second});
        }
        ans++;
    }
}