#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> adj[27];
int deg[27];
ll n,m;
queue <int> q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
  int n;
  cin >> n;
  map <char,int> mp;
  map <int,char> re_mp;
  int idx = 1;
  vector <string> a(n);
  for(int j=0;j<n;j++){
    cin >> a[j];
    for(int i=0;i<a[j].size();i++){
        if(mp.find(a[j][i])==mp.end()){
            mp[a[j][i]]=idx;
            re_mp[idx] = a[j][i];
            idx++;
        }
    }
  }
  int check = 1;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<a[i].size();j++){
        if(a[i+1].size()<=j){
            check = 0;
            break;
        }
        if(a[i][j]!=a[i+1][j]){
            int be = mp[a[i][j]], af = mp[a[i+1][j]];
            deg[af]++;
            adj[be].push_back(af);
            break;
        }
    }
  }
  if(check==0) {cout << "!"; return 0;}
  for(int i=1;i<=mp.size();i++){
    if(deg[i]==0) q.push(i);
  }
  check = 1;
  vector <int> ans;
  while(!q.empty()){
    if(q.size()>=2){
        check = 0;
    }
    int cur = q.front();
    ans.push_back(cur);
    q.pop();
    for(int i : adj[cur]){
        deg[i]--;
        if(deg[i]==0) q.push(i);
    }
  }
  if(ans.size()!=mp.size()) cout << "!";
  else{
    if(check==0){
        cout << "?";
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout << re_mp[ans[i]];
    }
  }

}  