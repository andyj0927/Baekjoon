#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,m,a[10],d[10];
void f(int x){
    if(x==m){
        for(int i=0;i<m;i++){
            cout << a[d[i]] << " ";
        }
        cout << endl;
        return;
    }
    int st = max(0,x-1);
    for(int i=d[st];i<n;i++){
        d[x] = i;
        f(x+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    f(0);
}