#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, s[10], w[10] , ans;
void f(int x){
    if(x==n){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]<=0) cnt++;
        }
        ans = max(ans,cnt);
        return;
    }
    bool exist = false;
    for(int i=0;i<n;i++){
        if(s[i]>=1 && i!=x){
            exist = true;
            break;
        }
    }
    if(s[x]<=0 || (!exist)){
        f(x+1);
    }
    else{
        for(int i=0;i<n;i++){
            if(x==i) continue;
            if(s[i]<=0) continue;
            s[x] -=w[i];
            s[i] -=w[x];
            f(x+1);
            s[x] +=w[i];
            s[i] +=w[x];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
        cin >> w[i];
    }
    f(0);
    cout << ans;
}