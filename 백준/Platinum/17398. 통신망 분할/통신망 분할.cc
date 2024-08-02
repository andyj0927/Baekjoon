#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
ll p[100001];
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    p[a]+=p[b];
    p[b] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,q;
    cin >> n >> m >> q;
    vector <pii> adj(m+1);
    fill(p,p+n+1,-1);
    for(int i=1;i<=m;i++) cin >> adj[i].first >> adj[i].second;
    vector <int> connect(q);
    vector <bool> connect_first(m+1,true);
    for(int i=q-1;i>=0;i--){
        int num;
        cin >> num;
        connect[i] = num;
        connect_first[num] = false;
    }
    for(int i=1;i<=m;i++){
        if(connect_first[i]){
            merge(adj[i].first,adj[i].second);
        }
    }
    ll ans = 0;
    for(int i=0;i<q;i++){
        int cur = connect[i];
        if(find(adj[cur].first)!=find(adj[cur].second)){
            ans += (p[find(adj[cur].first)]*p[find(adj[cur].second)]);
            merge(adj[cur].first,adj[cur].second);
        }
    }
    cout << ans;
}