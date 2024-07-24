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
    
    ll n;
    while(true){
        cin >> n;
        if(n==0) break;
        vector <ll> h(n+2);
        h[0] = 0;
        for(int i=1;i<=n;i++) cin >> h[i];
        h[n+1] = 0;
        stack <ll> st;
        ll ans = 0;
        for(int i=0;i<=n+1;i++){
            while(!st.empty() && h[st.top()]>h[i]){
                int cur = st.top();
                st.pop();
                ans = max(ans,(i-st.top()-1)*h[cur]);
            }
            st.push(i);
        }
        cout << ans << endl;
    }
    
}