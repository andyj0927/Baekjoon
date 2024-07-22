#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e8;

int dp[20][1<<16];
int a[20][20];
int n;
int f(int cur, int use){
    int &re = dp[cur][use];
    if(re!=-1) return re;
    if(use==((1<<n)-1)) return a[cur][0];
    re = MAXN;
    for(int i=0;i<n;i++){
        if(((use>>i)&1)==0){
            int curval = f(i,use|(1<<i))+a[cur][i];
            re = min(re,curval);
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
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]==0) a[i][j]=MAXN;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << f(0,1);
}