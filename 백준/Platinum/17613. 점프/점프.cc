#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
map <pll,int> mp;
int f(ll st, ll ed){
    if(mp.find({st,ed})!=mp.end()) return mp[{st,ed}];
    int re = 0;
    for(int i=1;i<31;i++){
        ll ns = (1ll<<i) -1;
        ll ne = (1ll<<(i+1)) - 2;
        ns = max(ns,st);
        ne = min(ne,ed);
        if(ns<=ne){
            ns = ns - (1ll<<i) + 1;
            ne = ne - (1ll<<i) + 1;
            re = max(re,f(ns,ne)+i);
        }
    }
    return mp[{st,ed}] = re;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        cout << f(x,y) << endl;
    }
    
}