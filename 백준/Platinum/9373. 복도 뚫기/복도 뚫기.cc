#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
tuple<ll,ll,ll> board[1000];
int p[1002];
double dist(tuple<ll,ll,ll> & a,tuple<ll,ll,ll> & b){
    auto [fx,fy,fr] = a;
    auto [sx,sy,sr] = b;
    double d = sqrt(pow(fx-sx,2)+pow(fy-sy,2));
    if(d<=fr+sr) return 0.0;
    else return d-fr-sr;
}
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
    int test;
    cin >> test;
    while(test--){
        ll w,n;
        cin >> w >> n;
        for(int i=0;i<n;i++){
            ll x,y,r;
            cin >> x >> y >> r;
            board[i] = {x,y,r};
        } 
        // n - 왼쪽벽, n+1 - 오른쪽벽
        fill(p,p+n+2,-1);
        vector <tuple<double,ll,ll>> adj;
        adj.push_back({w,n,n+1});
        for(int i=0;i<n;i++){
            auto [x,y,r] = board[i];
            adj.push_back({max(0ll,x-r),i,n});
            adj.push_back({max(0ll,w-x-r),i,n+1});
            for(int j=1;j<n;j++){
                adj.push_back({dist(board[i],board[j]),i,j});
            }
        }
        sort(adj.begin(),adj.end());
        for(int i=0;i<adj.size();i++){
            auto [val,a,b] = adj[i];
            if(val!=0) break;
            merge(a,b);
        }
        if(find(n)==find(n+1)){
            cout << 0 << endl;
            continue;
        }
        for(int i=0;i<adj.size();i++){
            auto [val,a,b] = adj[i];
            merge(a,b);
            if(find(n)==find(n+1)){
                cout << fixed << setprecision(6) << val/2 << endl;
                break;
            }
        }
    }

    
}