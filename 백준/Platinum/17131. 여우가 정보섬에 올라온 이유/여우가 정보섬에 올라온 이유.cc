#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e5;
const ll MOD = 1e9+7;
ll h;
int arr[MAXN*4];

void update(int i){
  i+=h;
  arr[i]+=1;
  while(i>1){
    i/=2;
    arr[i] = arr[i*2]+arr[i*2+1];
  }
}
ll cal(int l, int r, int nodenum, int nodel, int noder){
  if(l>noder || r < nodel) return 0;
  if(l<= nodel && noder <= r) return arr[nodenum];
  int mid = (nodel+noder)/2;
  return cal(l,r,nodenum*2,nodel,mid)+cal(l,r,nodenum*2+1,mid+1,noder);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  h = 1 << (int)ceil(log2(MAXN+1));
  vector <pii> a(n);
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    a[i]= {y,x+200000};
  }
  sort(a.begin(),a.end(),greater<>());
  ll ans=0;
  vector <int> up;
  for(int i=0;i<n;i++){
    if(i!=0 && a[i-1].first!=a[i].first){
      while(!up.empty()){
        int q = up[up.size()-1];
        update(q);
        up.pop_back();
      }
    }
    ll pl=cal(0,a[i].second-1,1,0,h-1)*cal(a[i].second+1,400000,1,0,h-1);
    pl%=MOD;
    ans+=pl;
    ans%=MOD;
    up.push_back(a[i].second);
  }
  cout << ans;
}