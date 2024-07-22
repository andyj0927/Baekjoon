#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e8, mod = 1e9+3;

ll dp[1003][1001];
int n,k;
ll f(int cur,int num){
    if(num<0) return 0;
    ll &re = dp[cur][num];
    if(re!=-1) return re;
    if(cur>=n){
        if(num==0) return re = 1;
        else return re = 0;
    }
    return re = (f(cur+1,num)+f(cur+2,num-1))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<=n+2;i++){
        for(int j=0;j<=n;j++) dp[i][j] = -1;
    }
    cout << (f(1,k)+f(3,k-1))%mod;
}