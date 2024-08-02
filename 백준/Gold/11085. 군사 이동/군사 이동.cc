#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[1001];
bool compare(tuple <int,int,int> &a, tuple<int,int,int> &b){
    return a>b;
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
    int pp,w , c, v;
    cin >> pp >> w >> c >> v;
    fill(p,p+pp+1,-1);
    vector <tuple <int,int,int>> adj;
    for(int i=0;i<w;i++){
        int st,ed,val;
        cin >> st >> ed >> val;
        adj.push_back({val,st,ed});
    }
    sort(adj.begin(),adj.end(),compare);
    for(int i=0;i<w;i++){
        auto [val,st,ed] = adj[i];
        merge(st,ed);
        if(find(c)==find(v)){
            cout << val;
            break;
        }
    }

}