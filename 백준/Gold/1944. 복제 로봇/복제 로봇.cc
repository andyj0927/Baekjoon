#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[252];
int board[50][50], vis[50][50];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    p[b] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int idx = 1;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1') board[i][j] = -1;
            if(s[j]=='S' || s[j]=='K'){
                board[i][j] = idx;
                idx++;
            }
        }
    }
    vector <tuple<int,int,int>> adj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]<=0) continue;
            for(int ii=0;ii<n;ii++){
                for(int jj=0;jj<n;jj++) vis[ii][jj] = 0;
            }
            queue <pii> q;
            q.push({i,j});
            vis[i][j]=1;
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = cur.first+dx[k];
                    int ny = cur.second+dy[k];
                    if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                    if(vis[nx][ny] || board[nx][ny]==-1) continue;
                    vis[nx][ny]=vis[cur.first][cur.second]+1;
                    q.push({nx,ny});
                    if(board[nx][ny]!=0){
                        adj.push_back({vis[nx][ny]-1,board[i][j],board[nx][ny]});
                    }
                }
            }
        }
    }
    int cnt = 0, ans = 0;
    sort(adj.begin(),adj.end());
    fill(p,p+m+2,-1);
    for(int i=0;i<adj.size();i++){
        auto [val,a,b] = adj[i];
        if(find(a)==find(b)) continue;
        merge(a,b);
        cnt++;
        ans+=val;
        if(cnt==m) break;
    }
    if(cnt==m) cout << ans;
    else cout << -1;
    
}