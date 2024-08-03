#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[501];
pii board[501];
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
        int s,n;
        cin >> s >> n;
        for(int i=0;i<n;i++){
            cin >> board[i].first >> board[i].second;
        }
        vector <tuple<double,int,int>> adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double val = sqrt(pow(board[i].first-board[j].first,2)+pow(board[i].second-board[j].second,2));
                adj.push_back({val,i,j});
            }
        }
        fill(p,p+n,-1);
        int cnt = s-1;
        if(cnt>=n-1){
            cout << fixed << setprecision(2) << 0.00 << endl;
            return 0;
        }
        sort(adj.begin(),adj.end());
        for(int i=0;i<adj.size();i++){
            auto [val,a,b] = adj[i];
            if(find(a)==find(b)) continue;
            merge(a,b);
            cnt++;
            if(cnt==n-1){
                cout << fixed << setprecision(2) << val << endl;
                break;
            }
        }
    }
    
}