#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i=0;i<n;i++) ans+=(n-i)*a[i];
    cout << ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int repeat = 1;
    while(repeat--){
        solve();
    }
    return 0;
}