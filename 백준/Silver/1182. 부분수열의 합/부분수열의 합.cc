#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,s,ans, sum, mx=-1,a[21];
void f(int x){
    for(int i=0;i<n;i++){
        if(mx>=i) continue;
        mx = i;
        sum+=a[i];
        if(sum == s){
            ans++;
        }
        f(i);
        sum-=a[i];
        mx = x;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    f(-1);
    cout << ans;
}