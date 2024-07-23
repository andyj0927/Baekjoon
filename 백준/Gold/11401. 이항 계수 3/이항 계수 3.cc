#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;

ll mul(ll a, ll t){
    if(t==0) return 1;
    ll re = mul(a,t/2);
    re = re*re;
    re%=MAXN;
    if(t%2==1) re *= a;
    return re%MAXN;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    ll h=1,l=1;
    for(int i=k+1;i<=n;i++){
        h*=i;
        h%=MAXN;
    }
    for(int i=1;i<=n-k;i++){
        l*=i;
        l%=MAXN;
    }
    cout << (h*mul(l,MAXN-2))%MAXN;
}