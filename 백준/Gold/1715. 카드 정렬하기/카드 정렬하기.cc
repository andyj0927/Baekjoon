#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

priority_queue<int,vector<int>,greater<int>> q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cin >> t; 
        q.push(t);
    }
    int ans= 0;
    while(!q.empty()){
        int a =q.top();
        q.pop();
        if(q.empty()){
            break;
        }
        int b =q.top();
        q.pop();
        ans+=(a+b);
        if(q.empty()){
            break;
        }
        q.push(a+b);
    }
    cout << ans;
}