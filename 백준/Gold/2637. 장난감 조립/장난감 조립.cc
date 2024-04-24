#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector <pll> a[105];
int deg[1005];
map <int,int> mp[105];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int m;
  cin >> m;
  while(m--){
    int x,y,k;
    cin >> x >> y >> k;
    a[y].push_back({x,k});
    deg[x]++;
  }
  queue <int> q;
  for(int i=1;i<=n;i++){
    if(deg[i]==0){
      q.push(i);
      mp[i][i] = 1;
    }
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(auto i : a[cur]){
      int product = i.first;
      int num = i.second;
      for(auto j : mp[cur]){
        mp[product][j.first]+=j.second*num;
      }
      deg[product]--;
      if(deg[product]==0) q.push(product);
    }
  }
  for(auto i : mp[n]) cout << i.first << " " << i.second << endl;

}  