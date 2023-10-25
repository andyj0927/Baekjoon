#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int check_nothole[101][101];
int vis[101][101];
int a[101][101][50];
int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};
int n,m;

void check(int x){
    memset(vis,0,sizeof(vis));
    memset(check_nothole,0,sizeof(vis));
    queue <pii> q;
    q.push({0,0});
    vis[0][0]=1;
    check_nothole[0][0]=1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.fi+dx[i];
            int ny = cur.se+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(a[nx][ny][x]||vis[nx][ny]) continue;
            check_nothole[nx][ny] = 1;
            q.push({nx,ny});
            vis[nx][ny]=1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j][0];
        }
    }
    int x=0;
    while(true){
        check(x);
        int ans = 0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(a[i][j][x]){
                    ans++;
                    int g=0;
                    for(int k=0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                        if(a[nx][ny][x] || !check_nothole[nx][ny]){
                            g++;
                        }
                    }
                    if(g==4) a[i][j][x+1] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j][x+1]) cnt++;
            }
        }
        if(cnt==0){
            cout << x+1 << endl;
            cout << ans;
            break;
        }
        x++;
    }
}