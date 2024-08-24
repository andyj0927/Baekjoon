#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e14;
const ll MOD = 1e9;
int table[500001][19];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,q;
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> table[i][0];
    }
    for(int i=1;i<19;i++){
        for(int j=1;j<=m;j++){
            table[j][i] = table[table[j][i-1]][i-1];
        }
    }
    cin >> q;
    while(q--){
        int n,x;
        cin >> n >> x;
        for(int i = 18;i>=0;i--){
            if((n>>i)&1){
                x = table[x][i];
            }
        }
        cout << x << endl;
    }

}