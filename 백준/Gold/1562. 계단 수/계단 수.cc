#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e14;
const ll MOD = 1e9;
ll d[101][10][1<<10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for(int i=1;i<10;i++){
        d[1][i][1<<i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<(1<<10);k++){
                if(j!=0){
                    d[i+1][j-1][k|(1<<(j-1))]+= d[i][j][k];
                    d[i+1][j-1][k|(1<<(j-1))]%=MOD;
                }
                if(j!=9){
                    d[i+1][j+1][k|(1<<(j+1))]+= d[i][j][k];
                    d[i+1][j+1][k|(1<<(j+1))]%=MOD;
                }
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<10;i++){
        ans+=d[n][i][(1<<10)-1];
        ans%=MOD;
    }
    cout << ans;

}