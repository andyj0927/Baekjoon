#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e8;

int dp[21][1<<21];
int a[21][21];
int n;
int f(int cur, int use){
    int &re = dp[cur][use];
    if(re!=-1) return re;
    if(cur==n) return 0;
    re = MAXN;
    for(int i=0;i<n;i++){
        if(((use>>i)&1)==0){
            re = min(re,f(cur+1,use+(1<<i))+a[cur][i]);
        }
    }
    return re;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> a[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout << f(0,0);
}