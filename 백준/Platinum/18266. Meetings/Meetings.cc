#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e9+7;
ll n,l;
struct Cow{
  ll x;
  ll w;
  ll d;
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> l;
  vector <Cow> a(n);
  vector <pll> to_go(n);
  for(int i=0;i<n;i++){
    cin >> a[i].w >> a[i].x >> a[i].d;
  }
  sort(a.begin(),a.end(),[](Cow &p, Cow &q){return p.x < q.x;});
  for(int i=0;i<n;i++){
    if(a[i].d==1){
      to_go[i].first = l-a[i].x;
    }
    else{
      to_go[i].first = a[i].x;
    }
    to_go[i].second = i;
  }
  sort(to_go.begin(),to_go.end());
  ll sum_w = 0;
  for(int i=0;i<n;i++) sum_w+=a[i].w;
  ll left=0, right = n-1;
  ll tot = 0, go = 0;
  for(int i=0;i<n;i++){
    if(a[to_go[i].second].d==1){
      tot+=a[right].w;
      right--;
    }
    else{
      tot+=a[left].w;
      left++;
    }
    if(tot>=(sum_w+1)/2){
      go = to_go[i].first;
      break;
    }
  }
  ll ed = 0, cnt = 0;
  ll ans = 0;
  for(int st=0;st<n;st++){
    while(ed<n && a[ed].x<=a[st].x+2*go){
      if(a[ed].d==-1) cnt++;
      ed++; 
    }
    if(a[st].d==-1){
      cnt--;
      continue;
    }
    ans+=(ll)cnt;
  }
  cout << ans;

}  