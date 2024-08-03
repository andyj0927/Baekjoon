#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[10];
int vis[11][11], board[11][11];
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> board[i][j];
    }
    int idx = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0 || vis[i][j]>=1) continue;
            queue <pii> q;
            q.push({i,j});
            vis[i][j] = idx;
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = cur.first+dx[k], ny = cur.second+dy[k];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(board[nx][ny]==0||vis[nx][ny]) continue;
                    q.push({nx,ny});
                    vis[nx][ny] = idx;
                }
            }
            idx++;
        }
    }
    vector <tuple<int,int,int>> adj;
    for(int i=0;i<n;i++){
        int flag = 0, be = -1;
        for(int j=0;j<m;j++){
            if(flag && j-be>=3 && board[i][j]){
                adj.push_back({(j-be-1),vis[i][j],vis[i][be]});
            }
            if(board[i][j]){
                flag = 1;
                be = j;
            }
        }
    }
    for(int j=0;j<m;j++){
        int flag = 0, be = -1;
        for(int i=0;i<n;i++){
            if(flag && i-be>=3 && board[i][j]){
                adj.push_back({(i-be-1),vis[i][j],vis[be][j]});
            }
            if(board[i][j]){
                flag = 1;
                be = i;
            }
        }
    }
    sort(adj.begin(),adj.end());
    int ans = 0, cnt = 0;
    fill(p,p+idx+1,-1);
    for(int i=0;i<adj.size();i++){
        auto [val,a,b] = adj[i];
        if(find(a)==find(b)) continue;
        merge(a,b);
        cnt++;
        ans+=val;
        if(cnt==idx-2){
            cout << ans;
            return 0;
        }
    }
    cout << -1;
}