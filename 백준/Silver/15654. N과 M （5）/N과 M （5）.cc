#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,m,a[10],d[10],v[10001];
void f(int x){
    if(x==m){
        for(int i=0;i<m;i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        if(v[a[i]]==1) continue;
        d[x] = a[i];
        v[a[i]]=1;
        f(x+1);
        v[a[i]]=0;
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