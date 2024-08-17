#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  vector <int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int l = 1, h = n, ans=-1;
  while(l<=h){
    int mid = (l+h)/2;
    int check = 0;
    queue <int> q;
    vector <int> vis(500001,0);
    for(int i=0;i<n;i++){
      if(vis[a[i]]==1){
        while(!q.empty() && q.front()!=a[i]){
          vis[q.front()]=0;
          q.pop();
        }
        q.pop();
      }
      vis[a[i]] = 1;
      q.push(a[i]);
      if(q.size()==mid){
        check++;
        while(!q.empty()){
          vis[q.front()] = 0;
          q.pop();
        }
      }
    }
    if(check>=m){
      ans = mid;
      l = mid+1;
    }
    else{
      h = mid-1;
    }
  }
  cout << ans;
}