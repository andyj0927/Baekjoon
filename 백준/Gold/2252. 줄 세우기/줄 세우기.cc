#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a[32001];
int deg[32001];
vector <int> ans;
ll n;
queue <int> q;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    deg[y]++;
  }
  for(int i=1;i<=n;i++){
    if(deg[i]==0){
      q.push(i);
    }
  }
  while(!q.empty()){
    int cur = q.front();
    cout << cur << " ";
    q.pop();
    for(int i : a[cur]){
      deg[i]--;
      if(deg[i]==0){
        q.push(i);
      }
    }
  }
}  