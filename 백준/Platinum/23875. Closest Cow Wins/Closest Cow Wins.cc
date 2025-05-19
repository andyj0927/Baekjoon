#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k,m,n;
    cin >> k >> m >> n;
    vector <pll> a(k);
    vector <int> cow(m);
    vector <ll> ans;
    for(int i=0;i<k;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++) cin >> cow[i];
    sort(cow.begin(),cow.end());
    int j = 0, be = cow[0];
    ll tot = 0;
    while(j<k && a[j].first<cow[0]){
        tot+=a[j].second;
        j++;
    }
    ans.push_back(tot);
    for(int i=1;i<m;i++){
        queue <pll> q;
        ll tot = 0, cur = 0, max_cur = 0;
        while(j<k && a[j].first<cow[i]){
            q.push({a[j].first,a[j].second});
            tot+= a[j].second;
            cur+= a[j].second;
            while(!q.empty() && a[j].first-q.front().first > (cow[i]-be-1)/2){
                cur-=q.front().second;
                q.pop();
            }
            max_cur = max(max_cur,cur);
            j++;
        }
        ans.push_back(max_cur);
        ans.push_back(tot-max_cur);
        be = cow[i];
    }
    tot = 0;
    while(j<k){
        tot+=a[j].second;
        j++;
    }
    ans.push_back(tot);
    sort(ans.begin(),ans.end(),greater());
    ll re = 0;
    for(int i=0;i<min(n,(int)ans.size());i++) re+=ans[i];
    cout << re;
}
