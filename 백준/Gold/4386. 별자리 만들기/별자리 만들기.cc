#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[101];
pair <double,double> board[101];
double dist(pair <double,double> & a, pair <double,double> &b){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
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
    int n;
    cin >> n;
    vector <tuple<double,int,int>> adj;
    fill(p,p+n,-1);
    for(int i=0;i<n;i++){
        cin >> board[i].first >> board[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            adj.push_back({dist(board[i],board[j]),i,j});
        }
    }
    sort(adj.begin(),adj.end());
    int cnt = 0;
    double ans = 0;
    for(int i=0;i<adj.size();i++){
        auto [val, a,b] = adj[i];
        if(find(a)==find(b)) continue;
        merge(a,b);
        cnt++;
        ans+=val;
        if(cnt==n-1) break;
    }
    cout << fixed << setprecision(2) << ans;
}