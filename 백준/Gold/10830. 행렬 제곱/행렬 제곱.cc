#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;

ll a[5][5],be[5][5], af[5][5];
ll n,b;
void mul(ll (&aa)[5][5],ll(&bb)[5][5]){
    ll c[5][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll cur = 0;
            for(int k=0;k<n;k++){
                cur+=aa[i][k]*bb[k][j];
                cur%=1000;
            }
            c[i][j] = cur;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) aa[i][j] = c[i][j];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {cin >> a[i][j]; be[i][j]=a[i][j]; if(i==j) af[i][j] = 1;}
    }
    while(b>0){
        if(b%2==1){
            mul(af,be);
        }
        mul(be,be);
        b/=2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout << af[i][j] << " ";
        cout << endl;
    }
}