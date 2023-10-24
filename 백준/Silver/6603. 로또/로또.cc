#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int k, a[14], d[14], v[14];
void f(int x){
    if(x==6){
        for(int i=0;i<6;i++){
            cout << a[d[i]] << " ";
        }
        cout << endl;
        return;
    }
    int st = max(0,x-1);
    for(int i=d[st];i<k;i++){
        if(v[i]!=0) continue;
        d[x] = i;
        v[i] = 1;
        f(x+1);
        v[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true){
        cin >> k;
        if(k==0){
            break;
        }
        fill(a,a+k,0);
        fill(v,v+k,0);
        fill(d,d+6,0);
        for(int i=0;i<k;i++){
            cin >> a[i];
        }
        f(0);
        cout << endl;
    }
}