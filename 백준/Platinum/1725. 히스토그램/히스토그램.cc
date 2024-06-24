#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 5e5+2;

int n, h[100005];

int histo(int l,int r){
  if(l==r) return 0;
  if(l+1==r) return h[l];
  int mid = (l+r)/2;
  int ans = max(histo(l,mid),histo(mid,r));
  int height = h[mid], low = mid, high = mid, weight = 1;
  while(high-low+1<r-l){
    int h1 = low>l ? min(height,h[low-1]) : -1;
    int h2 = high<r-1 ? min(height,h[high+1]) : -1;
    if(h1>=h2){
      height = h1;
      low--;
    }
    else{
      height = h2;
      high++;
    }
    ans = max(ans, (++weight)*height);
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n;i++) cin >> h[i];
  cout << histo(0,n);
}