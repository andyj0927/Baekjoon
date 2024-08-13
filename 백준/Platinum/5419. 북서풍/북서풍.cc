#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 75000*4;
ll h;
ll arr[MAXN];

void update(ll cur){
  cur+=h;
  arr[cur]+=1;
  while(cur>1){
    cur/=2;
    arr[cur] = arr[cur*2]+arr[cur*2+1];
  }
}
ll cal(ll l, ll r , ll nodenum , ll nodel, ll noder){
  if(nodel>r || noder<l) return 0;
  if(l<=nodel && noder<=r) return arr[nodenum];
  ll mid = (nodel+noder)/2;
  return cal(l,r,nodenum*2,nodel,mid)+cal(l,r,nodenum*2+1,mid+1,noder);
}
bool compare(const pll &a, const pll &b){
  if(a.second==b.second) return a.first<b.first;
  return a.second>b.second;
}
void solve(){
  ll n;
  cin >> n;
  vector <pll> a(n);
  for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(),a.end(),compare);
  int idx = 0;
  ll be = a[0].second;
  for(int i=0;i<n;i++){
    if(be==a[i].second){
      a[i].second = idx;
    }
    else{
      idx++;
      be = a[i].second;
      a[i].second = idx;
    }
  }
  sort(a.begin(),a.end());
  h = 1 << ((int)ceil(log2(idx+1)));
  ll ans = 0;
  for(int i=0;i<2*h;i++) arr[i] = 0;
  for(int i=0;i<n;i++){
    ans+=cal(0,a[i].second,1,0,h-1);
    update(a[i].second);
  }
  cout << ans << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int repeat;
  cin >> repeat;
  while(repeat--){
    solve();
  }
}