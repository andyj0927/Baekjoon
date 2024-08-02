#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 5e5+7;
pii p[300001];
int find(int n){
    if(p[n].first<0) return n;
    p[n].first = find(p[n].first);
    return p[n].first;
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return;
    p[a].first +=p[b].first;
    p[b].first = a;
    p[a].second +=p[b].second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l;
    cin >> n  >> l;
    for(int i=1;i<=l;i++){
        p[i].first = -1;
        p[i].second = 0;
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        merge(a,b);
        int pa = find(a);
        if(p[pa].second==p[pa].first*-1){
            cout << "SMECE" << endl;
        }
        else{
            p[pa].second++;
            cout << "LADICA" << endl;
        }
    }

}