#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
ll p[1001];
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
    vector <tuple<int,int,int>> adj(m);
    fill(p,p+n+1,-1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[i] = {c,a,b};
    }
    sort(adj.begin(),adj.end());
    int cnt = 0, ans = 0;
    for(int i=0;i<m;i++){
        auto [val, a,b] = adj[i];
        if(find(a)==find(b)) continue;
        merge(a,b);
        cnt++;
        ans+=val;
        if(cnt==n-1) break;
    }
    cout << ans;
}