#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[4000005];
int vis[2001][2001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    p[y] = x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    fill(p,p+n*n,-1);
    queue <pair<int,int>> q;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        q.push({x,y});
        p[(x-1)*n+y-1] = -2;
        vis[x][y] = 1;
    }
    int ans = 0;
    while(true){
        queue <pii> nq;
        while(!q.empty()){
            auto cur = q.front();
            nq.push(cur);
            q.pop();
            for(int i=0;i<4;i++){
                int nx = cur.first+dx[i];
                int ny= cur.second+dy[i];
                if(nx<=0 || nx>n || ny<=0 || ny>n) continue;
                int m1 = (cur.first-1)*n+cur.second-1;
                int m2 = (nx-1)*n + ny-1;
                if(p[find(m2)]!=-1){
                    if(find(m1)!=find(m2)){
                        merge(m1,m2);
                        k--;
                    }
                }
            }
        }
        if(k==1) {cout << ans; break;}
        q= nq;
        while(!nq.empty()) nq.pop();
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = cur.first+dx[i];
                int ny= cur.second+dy[i];
                if(nx<=0 || nx>n || ny<=0 || ny>n) continue;
                if(vis[nx][ny]) continue;
                int m1 = (cur.first-1)*n+cur.second-1;
                int m2 = (nx-1)*n + ny-1;
                vis[nx][ny] = 1;
                nq.push({nx,ny});
                merge(m1,m2);
            }
        }
        ans++;
        q = nq;
    }
}