#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n,w,l, a[1002] , t[1002];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> w >> l;
  for(int i=0;i<n;i++) cin >> a[i];
  t[0] = 1;
  int sum = a[0];
  int front = 0;
  for(int i=1;i<n;i++){
    while(sum+a[i]>l || i-front+1>w){
      sum-= a[front];
      front++;
    }
    sum+=a[i];
    if(front==0){
      t[i] = t[i-1]+1;
    }
    else{
      t[i] = max(t[front-1]+w, t[i-1]+1);
    }
  }
  cout << t[n-1] + w;

}  