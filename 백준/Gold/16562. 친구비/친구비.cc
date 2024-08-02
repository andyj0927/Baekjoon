#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e6+7;
int p[10002];
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(p[x]<p[y]) p[x] = y;
    else p[y] = x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        p[i] = -1*a;
    }
    for(int i=0;i<m;i++){
        int v,w;
        cin >> v >> w;
        merge(v,w);
    }
    set <int> s;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int pi = find(i);
        if(s.find(pi)==s.end()){
            ans+= p[pi]*-1;
            s.insert(pi);
        }
    }
    if(ans>k) cout << "Oh no";
    else cout << ans;

}