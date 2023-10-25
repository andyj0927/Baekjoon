#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

priority_queue<int,vector<int>> q;
pii a[300001];
int back[300001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i].fi >> a[i].se;
    }
    for(int i=0;i<k;i++){
        cin >> back[i];
    }
    sort(a,a+n);
    sort(back,back+k);
    ll j=0, sum = 0;
    for(int i=0;i<k;i++){
        while(j<n && a[j].fi<=back[i]){
            q.push(a[j].se);
            j++;
        }
        if(!q.empty()){
            sum+=q.top();
            q.pop();
        }
    }
    cout << sum;

}