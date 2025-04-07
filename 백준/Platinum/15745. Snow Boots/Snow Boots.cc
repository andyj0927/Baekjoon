#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;
ll n,b;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> b;
  priority_queue<pii,vector<pii>,greater<pii>> pq;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(i==0 || i==n-1) continue;
    pq.push({x,i}); // 깊이 거리
  }
  set <int> st;
  multiset <int> mulst;
  st.insert(0);
  st.insert(n-1);
  mulst.insert(n-1);
  map <int,int> ans;
  ans[0] = n-1; // 깊이에 따른 거리
  while(!pq.empty()){
    auto [s,idx] = pq.top(); // 깊이 거리
    pq.pop();
    auto l=st.lower_bound(idx);
    int cur1 = *l-idx;
    int cur2 =idx-*(--l);
    mulst.erase(mulst.find(cur1+cur2));
    mulst.insert(cur1);
    mulst.insert(cur2);
    ans[s]=*prev(mulst.end());
    st.insert(idx);
  }
  for(int i=0;i<b;i++){
    int s,d;
    cin >> s >> d; // 깊이 거리 s>=key 를 찾아야 함 -> 
    auto idx = ans.upper_bound(s);
    if(d>=(--idx)->second) cout << 1 << endl;
    else cout << 0 << endl;
  }
}