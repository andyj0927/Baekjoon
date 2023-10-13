#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a;
vector <int> b;
vector <int> a2;
map <int,int> mp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        a.push_back(t);
        a2.push_back(t);
    }
    sort(a.begin(),a.end());
    b.push_back(a[0]);
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            continue;
        }
        else{
            b.push_back(a[i+1]);
        }
    }
    int m= b.size();
    for(int i=0;i<m;i++){
        mp.insert(pair<int,int>(b[i],i));
    }
    for(int i=0;i<n;i++){
        cout << mp[a2[i]] << " ";
    }
}