#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,k;
int a[101];
int d[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    d[0]=1;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=k;j++){
            d[j]+=d[j-a[i]];
        }
    }
    cout << d[k];
}