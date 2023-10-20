#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<pair<int,int>> a;
int d[1003][1003];
int r[1003];
int n,w;
int dist(int x, int y, int xx, int yy){
    return abs(x-xx)+abs(y-yy);
}

int tot(int p1, int p2){
    if(p1==w || p2==w) return 0;
    if(d[p1][p2]!=-1) return d[p1][p2];
    int next = max(p1,p2)+1;
    int d1 , d2;

    if(p1==0) d1 = dist(1,1,a[next-1].fi,a[next-1].se);
    else d1 = dist(a[p1-1].fi,a[p1-1].se,a[next-1].fi,a[next-1].se);
    if(p2==0) d2 = dist(n,n,a[next-1].fi,a[next-1].se);
    else d2 = dist(a[p2-1].fi,a[p2-1].se,a[next-1].fi,a[next-1].se);

    d[p1][p2]=min(d1+tot(next,p2),d2+tot(p1,next));
    return d[p1][p2];
}
void re(int p1, int p2){
    if(p1==w || p2==w) return;
    int next = max(p1,p2)+1;
    int d1 , d2;
    if(p1==0) d1 = dist(1,1,a[next-1].fi,a[next-1].se);
    else d1 = dist(a[p1-1].fi,a[p1-1].se,a[next-1].fi,a[next-1].se);
    if(p2==0) d2 = dist(n,n,a[next-1].fi,a[next-1].se);
    else d2 = dist(a[p2-1].fi,a[p2-1].se,a[next-1].fi,a[next-1].se);
    if(d1+tot(next,p2)>d2+tot(p1,next)){
        cout << 2 << endl;
        re(p1,next);
    }
    else{
        cout << 1 << endl;
        re(next,p2);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for(int i=0;i<w;i++){
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    memset(d,-1,sizeof(d));
    cout << tot(0,0) << endl;
    re(0,0);
    return 0;
}
