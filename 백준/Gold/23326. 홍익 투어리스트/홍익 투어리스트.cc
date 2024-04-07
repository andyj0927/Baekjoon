#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin >> n >> q;
    set <ll> st;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x) st.insert(i+1);
    }
    ll cur = 1;
    for(int i=0;i<q;i++){
        ll x,y;
        cin >> x;
        if(x==1){
            cin >> y;
            if(st.find(y)==st.end()){
                st.insert(y);
            }
            else{
                st.erase(y);
            }
        }
        else if(x==2){
            cin >>  y;
            cur = (cur+y-1)%n+1;
        }
        else{
            if(st.lower_bound(cur)!=st.end()){
                cout << *st.lower_bound(cur)- cur << endl;
            }
            else if(st.size()){
                cout << *st.begin()+n-cur << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }

}