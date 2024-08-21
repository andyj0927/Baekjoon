#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e14;
ll d[2501][2501];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector <ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    priority_queue <pair<ll,pll>, vector <pair<ll,pll>>, greater<pair<ll,pll>>> pq;
    vector <pll> adj[n+1];
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin >> u >> v >>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2500;j++) d[i][j] = MAXN;
    }
    pq.push({0,{1,a[1]}});
    d[1][a[1]] = 0;
    while(!pq.empty()){
        auto [val,cur] = pq.top();
        pq.pop();
        if(d[cur.first][cur.second]!=val) continue;
        for(auto next : adj[cur.first]){
            if( d[next.second][min(cur.second,a[next.second])]> d[cur.first][cur.second]+next.first*cur.second){
                d[next.second][min(cur.second,a[next.second])] = d[cur.first][cur.second]+next.first*cur.second;
                pq.push({d[cur.first][cur.second]+next.first*cur.second,{next.second,min(cur.second,a[next.second])}});
            }
        }
    }
    ll ans = MAXN;
    for(int i=1;i<=2500;i++){
        ans = min(ans,d[n][i]);
    }
    cout << ans;
}