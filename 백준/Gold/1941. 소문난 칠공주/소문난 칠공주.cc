#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int d[8], v[6][6] , ans;
int vis[26];
string s[5];
int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};
bool four(){
    int nm=0;
    for(int i=0;i<7;i++){
        int nx = d[i]/5;
        int ny = d[i]%5;
        if(s[nx][ny]=='S') nm++;
    }
    if(nm>=4) return true;
    else return false;
}
bool adj(){
    queue <pii> q;
    q.push({d[0]/5,d[0]%5});
    memset(v,0,sizeof(v));
    v[d[0]/5][d[0]%5] = 1;
    int cnt = 1;
    bool adjans = false;
    while(!q.empty()){
        if(cnt==7){
            adjans=true;
            break;
        }
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || ny<0 || nx>=5 || ny>=5) continue;
            if(vis[nx*5+ny]==0 || v[nx][ny]) continue;
            q.push({nx,ny});
            v[nx][ny] = 1;
            cnt++;
        }
    }
    return adjans;
}

void f(int x){
    if(x==7){
        if(four()){
            if(adj()){
                ans++;
            }
        }
        return;
    }
    for(int i=d[max(0,x-1)];i<25;i++){
        if(vis[i]) continue;
        vis[i] = 1;
        d[x] = i;
        f(x+1);
        vis[i] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<5;i++){
        cin >> s[i];
    }
    f(0);
    cout << ans;
}