#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 1e8;

ll dp[1<<15][100];
string a[20];
int amod[20];
int multi[51];
int n,k;
ll cal(string &s){
    ll re = 0;
    for(int i=0;i<s.length();i++){
        re += multi[i]*(s[s.length()-1-i]-'0');
        re%=k;
    }
    return re;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> k;
    dp[0][0] = 1;
    int curmul = 1;
    for(int i=0;i<=50;i++){
        multi[i] = curmul;
        curmul*=10;
        curmul%=k;
    }
    for(int i=0;i<n;i++){
        amod[i] = cal(a[i]);
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(((i>>j)&1)==0){
                for(int mod=0;mod<k;mod++){
                    int newmod = mod*multi[a[j].length()];
                    newmod+=amod[j];
                    newmod%=k;
                    dp[i+(1<<j)][newmod]+=dp[i][mod];
                }
            }    
        }
    }
    ll tot = 1;
    for(int i=1;i<=n;i++) tot*=i;
    ll divid = gcd(tot,dp[(1<<n)-1][0]);
    cout << dp[(1<<n)-1][0]/divid << "/" << tot/divid;
}