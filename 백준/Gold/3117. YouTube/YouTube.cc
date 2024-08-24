#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e14;
const ll MOD = 1e9;
int table[100001][30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,m;
    cin >> n >> k >> m;
    m--;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<=k;i++){
        cin >> table[i][0];
    }
    for(int i=1;i<30;i++){
        for(int j=1;j<=k;j++){
            table[j][i] = table[table[j][i-1]][i-1];
        }
    }
    for(int i=0;i<n;i++){
        int x = a[i];
        for(int j=29;j>=0;j--){
            if((m>>j)&1) x = table[x][j];
        }
        cout << x << " ";
    }

}