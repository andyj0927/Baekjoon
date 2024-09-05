#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[101];
int n;
int back(int cur){
  int rad = 1 , cnt = 0;
  while(cur>0){
    int check = 0;
    int be= cur;
    while(cur-1>=0 && a[cur-1]>=a[be]-rad){
      cnt++;
      cur--;
      check = 1;
    }
    rad++;
    if(!check) break;
  }
  return cnt;
}
int front(int cur){
  int rad = 1 , cnt = 0;
  while(cur<n-1){
    int check = 0;
    int be = cur;
    while(cur+1<n && a[cur+1]<=a[be]+rad){
      cnt++;
      cur++;
      check = 1;
    }
    rad++;
    if(!check) break;
  }
  return cnt;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a,a+n);
  int ans = 0;
  for(int i=0;i<n;i++){
    ans = max(ans,back(i)+front(i)+1);
  }
  cout << ans;
}