#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[MAXN];
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    p[x] +=p[y];
    p[y] = x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    fill(p,p+n,-1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        if(find(a)==find(b)){
            cout << i;
            return 0;
        }
        merge(a,b);
    }
    cout << 0;
}