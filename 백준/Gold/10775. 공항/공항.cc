#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
int p[100001];
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    p[b] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int g,pp;
    cin >> g >> pp;
    fill(p,p+g+1,-1);
    int ans = 0;
    for(int i=0;i<pp;i++){
        int x;
        cin >> x;
        int y = find(x);
        if(y==0) break;
        merge(y-1,y);
        ans++;
    }
    cout << ans;

}