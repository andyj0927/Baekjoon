#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
ll n,q,h;
ll arr[MAXN];
void update(ll i , ll val){
  i+=h;
  arr[i] +=val;
  while(i>1){
    i/=2;
    arr[i] = arr[i*2]+arr[i*2+1];
  }
}
ll sum(ll l , ll r, ll nodenum , ll nodel, ll noder){
  if(nodel>r || noder<l) return 0;
  if(l <= nodel && noder <= r) return arr[nodenum];
  ll mid = (nodel+noder)/2;
  return sum(l,r,nodenum*2,nodel,mid)+sum(l,r,nodenum*2+1,mid+1,noder);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  h = 1 << ((int)ceil(log2(n)));
  while(q--){
    ll a,b,c;
    cin >> a >> b >> c;
    if(a==1){
      update(b-1,c);
    }
    else{
      cout << sum(b-1,c-1,1,0,h-1) << endl;
    }
  }
}