#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e8;
int num[10001];
vector <int> adj[10001];
int dp[10001][2];
int f(int cur, int p, int choose){
    int &re = dp[cur][choose];
    if(re!=-1) return re;
    re = 0;
    if(choose){
        re+=num[cur];
        for(int next : adj[cur]){
            if(next==p) continue;
            re+=f(next,cur,0);
        }
    }
    else{
        for(int next : adj[cur]){
            if(next==p) continue;
            re+=max(f(next,cur,1),f(next,cur,0));
        }
    }
    return re;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; // 10000
    cin >> n;
    for(int i=1;i<=n;i++) cin >> num[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    cout << max(f(1,-1,1),f(1,-1,0));
}