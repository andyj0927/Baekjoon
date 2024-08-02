#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
ll p[100001], vis[100001];
pll s[100001];
int find(int n){
    if(p[n]<0) return n;
    p[n] = find(p[n]);
    return p[n];
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    p[a]+=p[b];
    p[b] = a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]*=-1;
        cin >> s[i].first;
        s[i].second = i;
    }
    sort(s,s+n);
    for(int i=0;i<n;i++){
        int cur = s[i].second;
        vis[cur] = 1;
        if(cur>0 && vis[cur-1]) merge(cur-1,cur);
        if(cur<n-1 && vis[cur+1]) merge(cur+1,cur);
        if(p[find(cur)]*-1>=m){
            cout << s[i].first;
            break;
        }
    }
}