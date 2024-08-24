#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e14;
const ll MOD = 1e9;
int table[100001][14];
ll d[100001][14];
vector <pll> adj[100001];
void dfs(int cur,int p){
    for(auto next : adj[cur]){
        if(next.first!=p){
            table[next.first][0] = cur;
            d[next.first][0] = next.second;
            dfs(next.first,cur);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector <ll> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,-1);
    d[1][0] = 0;
    table[1][0] = 1;
    for(int i=1;i<14;i++){
        for(int j=1;j<=n;j++){
            table[j][i] = table[table[j][i-1]][i-1];
            d[j][i] = d[j][i-1]+d[table[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=n;i++){
        int x = i;
        for(int j=13;j>=0;j--){
            if(a[i]>=d[x][j]){
                a[i]-=d[x][j];
                x = table[x][j];
            }
        }
        cout << x << endl;
    }
}