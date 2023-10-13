#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack <int> st;
    ll sum=0;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        while(!st.empty() && st.top()<=t){
            st.pop();
            sum+=st.size();
        }
        st.push(t);
    }
    sum += (st.size()-1)*st.size()/2;
    cout << sum;
}  