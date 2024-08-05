#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> adj[501];
int deg[501];
int past[501];
int ans[501];
ll n,m;
queue <int> q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int repeat;
  cin >> repeat;
  while(repeat--){
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) {deg[i] = 0; ans[i] = -1;}
    cin >> n;
    for(int i=1;i<=n;i++) cin >> past[i];
    cin >> m;
    map <pii,int> mp;
    while(m--){
        int x,y;
        cin >> x >> y;
        mp[{x,y}] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(mp[{past[i],past[j]}] || mp[{past[j],past[i]}]){
                adj[past[j]].push_back(past[i]);
                deg[past[i]]++;
            }
            else{
                adj[past[i]].push_back(past[j]);
                deg[past[j]]++;
            }
        }
    }
    int idx = 0;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) q.push(i);
    }
    if(q.size()==1){
        ans[1] = q.front();
    }
    idx = q.size();
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int check = 0;
        if(q.empty()) check = 1;
        for(int i : adj[cur]){
            deg[i]--;
            if(deg[i]==0){
                q.push(i);
                idx++;
            }
        }
        if(q.size()==1 && check){
            ans[idx] = q.front();
        }
    }
    if(idx!=n) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=1;i<=n;i++){
            if(ans[i]!=-1)cout << ans[i] << " ";
            else cout << "? ";
        }
        cout << endl;
    }
  }
}  