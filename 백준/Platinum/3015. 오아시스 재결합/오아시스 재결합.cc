#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    stack <pll> st;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll cur = 0, tot = 0;
        while(!st.empty() && st.top().first <a[i]){
            cur+=st.top().second;
            st.pop();
        }
        if(!st.empty() && st.top().first == a[i]){
            cur+=st.top().second;
            tot = st.top().second;
            st.pop();
        }
        if(!st.empty())cur+=1;
        st.push({a[i],1+tot});
        ans+=cur;
    }
    cout << ans;
}