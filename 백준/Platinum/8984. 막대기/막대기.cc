#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e14;
ll d[100001][2];
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
    map <pll,vector <int>> mp;
    for(int i =0;i<n;i++){
        mp[{a[i].first,0}].push_back(i);
        mp[{a[i].second,1}].push_back(i);
    }
    for(int i=0;i<n;i++){
        d[i][0] = lena[i];
        d[i][1] = lena[i];
        for(auto j : mp[{a[i].first,0}]){
            if(i==j) continue;
            if(a[i].second<a[j].second) continue;
            d[i][0] = max(d[i][0],d[j][1]+lena[i]);
        }
        for(auto j : mp[{a[i].second,1}]){
            if(i==j) continue;
            if(a[i].first<a[j].first) continue;
            d[i][1] = max(d[i][1],d[j][0]+lena[i]);
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j : {0,1}){
            ans = max(ans,d[i][j]);
        }
    }
    cout << ans;
}