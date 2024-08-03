#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
ll p[20001],dis[20001];
int find(int n){
    if(p[n]<0){
        return n;
    }
    int idx = find(p[n]);
    dis[n] += dis[p[n]];
    return p[n]=idx;
}
void merge(int a, int b){
    int temp = abs(a-b)%1000;
    dis[a] = temp;
    p[a] = b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fill(p,p+n+1,-1);
        fill(dis,dis+n+1,0);
        while(true){
            char q;
            cin >> q;
            if(q=='O') break;
            if(q=='I'){
                int i,j;
                cin >> i >> j;
                merge(i,j);
            }
            if(q=='E'){
                int  i,j;
                cin >> i;
                j = find(i);
                cout << dis[i] << endl;
            }
        }
    }
}