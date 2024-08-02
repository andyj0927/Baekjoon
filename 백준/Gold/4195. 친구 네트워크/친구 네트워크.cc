#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e6+7;

int find(int n, vector <int> &p){
    if(p[n]<0) return n;
    p[n] = find(p[n],p);
    return p[n];
}
void merge(int x, int y, vector <int> &p){
    x = find(x,p);
    y = find(y,p);
    if(x==y) return;
    p[x] +=p[y];
    p[y] = x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int f;
        cin >> f;
        int index = 1;
        map <string,int> mp;
        vector <int> p(2*f+1);
        for(int i=0;i<f;i++){
            string s1,s2;
            cin >> s1 >> s2;
            if(mp.find(s1)==mp.end()){
                mp[s1] = index;
                p[index] = -1;
                index++;
            }
            if(mp.find(s2)==mp.end()){
                mp[s2] = index;
                p[index] = -1;
                index++;
            }
            int a,b;
            a = mp[s1], b = mp[s2];
            merge(a,b,p);
            cout << -1*p[find(a,p)] << endl;
        }
    }

}