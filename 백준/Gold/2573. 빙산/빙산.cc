#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[301][301];
int counta[301][301];
int v[301][301];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int t=1;
    while(true){
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                for(int k=0;k<4;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(!a[nx][ny]) counta[i][j]++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j]=max(a[i][j]-counta[i][j],0);
                counta[i][j] = 0;
                v[i][j] = 0;
            }
        }


        int cnt=0;
        int x,y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!=0) {cnt++; x=i; y=j;}
            }
        }
        if(cnt==0){
            cout << 0;
            return 0;
        }
        queue <pair<int,int>> q;
        q.push({x,y});
        v[x][y]=1;
        int count = 1;
        while(!q.empty()){
            auto cur =q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nx = cur.fi + dx[k];
                int ny = cur.se + dy[k];
                if(nx<0 || ny<0 || nx >=n || ny >= m) continue;
                if(a[nx][ny]==0||v[nx][ny]) continue;
                q.push({nx,ny});
                v[nx][ny]=1;
                count++;
            }
        }
        if(count!=cnt){
            cout << t;
            return 0;
        }
        t++;
    }


}