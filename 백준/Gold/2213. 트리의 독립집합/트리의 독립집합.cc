#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
ll n;
ll w[10001];
vector <int> adj[10001];
vector <int> ans;
ll d[10001][2];
ll f(int cur, int par, int inset){
  ll &re = d[cur][inset];
  if(re!=-1) return re;
  re = 0;
  if(inset){
    for(auto i : adj[cur]){
      if(par!=i){
        re+=f(i,cur,0);
      }
    }
    re+=w[cur];
  }
  else{
    for(auto i : adj[cur]){
      if(par!=i){
        re+=max(f(i,cur,1),f(i,cur,0));
      }
    }
  }
  return re;
}
void check(int cur, int par, int mustnotin){
  if(mustnotin==1){
    for(auto i : adj[cur]){
      if(i!=par){
        check(i,cur,0);
      }
    }
    return;
  }
  else if(f(cur,par,0)<f(cur,par,1)){
    ans.push_back(cur);
    for(auto i : adj[cur]){
      if(i!=par){
        check(i,cur,1);
      }
    }
    return;
  }
  else{
    for(auto i : adj[cur]){
      if(i!=par){
        check(i,cur,0);
      }
    }
    return;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=1;i<=n;i++) cin >> w[i];
  for(int i=0;i<n-1;i++){
    int v,u;
    cin >> v >> u;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<2;j++) d[i][j] = -1;
  }
  ll tot = max(f(1,0,0),f(1,0,1));
  cout << tot << endl;
  check(1,0,0);
  sort(ans.begin(),ans.end());
  for(auto i : ans) cout << i << " ";
}