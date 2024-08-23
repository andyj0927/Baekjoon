#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e14;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,l;
    cin >> n >> l;
    vector <pll> a(n);
    vector <ll> lena(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        lena[i] = llabs(a[i].first-a[i].second)+l;
    }
    map <ll,ll> up, down;
    for(int i=0;i<n;i++){
        up[a[i].first] = 0;
        down[a[i].second] = 0;
    }
    for(int i=0;i<n;i++){
        ll beup = up[a[i].first], bedown = down[a[i].second];
        down[a[i].second] = max(bedown,beup+lena[i]);
        up[a[i].first] = max(beup,bedown+lena[i]);
    }
    ll ans = 0;
    for(auto i : up){
        ans = max(ans,i.second);
    }
    for(auto i : down){
        ans = max(ans,i.second);
    }
    cout << ans;
}