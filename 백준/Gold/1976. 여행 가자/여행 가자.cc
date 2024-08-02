#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e6+7;
int p[202];
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    p[y] = x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    fill(p,p+n+1,-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int connect;
            cin >> connect;
            if(connect==1) merge(i,j);
        }
    }
    int f, check = 1;
    cin >> f;
    f= find(f);
    for(int i=1;i<m;i++){
        int se;
        cin >> se;
        if(find(se)!=f){
            check = 0;
            break;
        }
    }
    if(check) cout << "YES" << endl;
    else cout << "NO" << endl;
}