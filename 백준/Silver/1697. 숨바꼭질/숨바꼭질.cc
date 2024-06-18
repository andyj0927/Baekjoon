#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int t[200002];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    fill(t,t+100001,-1);
    cin >> n >> k;
    queue <int> q;
    t[n] = 0;
    if(n==k) cout << t[n];
    else q.push(n);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i: {cur*2,cur+1,cur-1}){
            if(i>=200000 || i<0) continue;
            if(t[i]!=-1) continue;
            t[i] = t[cur] +1;
            if(i==k){cout << t[i]; return 0;}
            q.push(i);
        }
    }

}