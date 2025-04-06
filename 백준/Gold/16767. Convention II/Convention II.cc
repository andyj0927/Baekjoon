#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;
ll n,k;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  vector <tuple<int,int,int>> a(n);
  for(int i=0;i<n;i++){
    int st, ed;
    cin >> st >> ed;
    ed+=st;
    a[i] = {st,i,ed};
  }
  sort(a.begin(),a.end());
  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
  int be=0;
  int ans = 0;
  for(int i=0;i<n;i++){
    auto [st,pri,ed] = a[i];
    pq.push({pri,st,ed});
    while(!pq.empty()){
      auto [cur_pri,cur_st,cur_ed] = pq.top();
      pq.pop();
      if(be>cur_st){
        ans=max(ans,be-cur_st);
        be = be+(cur_ed-cur_st);
      }
      else{
        be= cur_ed;
      }
      while(i<n-1){
        auto [next_st,next_pri,next_ed] = a[i+1];
        if(next_st>be) break;
        i++;
        pq.push({next_pri,next_st,next_ed});
      }
    }
  }
  cout << ans;
}  