#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,m,d[10],v[10002], nm;
vector <int> a;
void f(int x){
    if(x==m){
        for(int i=0;i<m;i++){
            cout << a[d[i]] << " ";
        }
        cout << endl;
        return;
    }
    int st = max(0,x-1);
    for(int i=d[st];i<nm;i++){
        if(v[a[i]]==0) continue;
        d[x] = i;
        v[a[i]]--;
        f(x+1);
        v[a[i]]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if(v[t]==0) a.push_back(t);
        v[t]++;
    }
    sort(a.begin(),a.end());
    nm= a.size();
    f(0);
}