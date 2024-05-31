#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 1e15;
// 1 : 2  // 7:3 // 2: 5 // 6: 6 // 8 : 7 //
ll d[102][52];
ll f(ll tot, ll len){
  ll &re = d[tot][len];
  if(re!=-1) return re; 
  if(len==0){
    if(tot==0) return re =1;
    else re  = 0;
  }
  re = 0;
  if(tot<=1) return re = 0;
  if(tot>=2) re |= f(tot-2,len-1);
  if(tot>=3) re |= f(tot-3,len-1);
  if(tot>=4) re |= f(tot-4,len-1);
  if(tot>=5) re |= f(tot-5,len-1);
  if(tot>=6) re |= f(tot-6,len-1);
  if(tot>=7) re |= f(tot-7,len-1);
  return re;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for(int i=0;i<=100;i++){
    for(int j=0;j<=51;j++) d[i][j] = -1;
  }
  while(t--){
    int n;
    cin >> n;
    int ans;
    int m = n;
    for(int i=1;i<=50;i++){
      if(f(n,i)){
        ans = i;
        break;
      }
    }
    for(int i=ans;i>=1;i--){
      if(n>=6 && f(n-6,i-1) && i!=ans){
        cout << 0;
        n-=6;
      }
      else if( n>=2 && f(n-2,i-1)){
        cout << 1;
        n-=2;
      }
      else if(n>=5 &&f(n-5,i-1)){
        cout << 2;
        n-=5;
      }
      else if(n>=4 &&f(n-4,i-1)){
        cout << 4;
        n-=4;
      }
      else if(n>=6 &&f(n-6,i-1)){
        cout << 6;
        n-=6;
      }
      else if(n>=3 &&f(n-3,i-1)){
        cout << 7;
        n-=3;
      }
      else{
        cout << 8;
        n-=7;
      }
    }
    cout << " ";

    n = m;


    for(int i=50;i>=1;i--){
      if(f(n,i)){
        ans = i;
        break;
      }
    }
    for(int i=ans;i>=1;i--){
      if(n>=6 && f(n-6,i-1)){
        cout << 9;
        n-=6;
      }
      else if(n>=7 &&f(n-7,i-1)){
        cout << 8;
        n-=7;
      }
      else if(n>=3 &&f(n-3,i-1)){
        cout << 7;
        n-=3;
      }
      else if(n>=5 &&f(n-5,i-1)){
        cout << 5;
        n-=5;
      }
      else if(n>=4 &&f(n-4,i-1)){
        cout << 4;
        n-=4;
      }
      else{
        cout << 1;
        n-=2;
      }
    }
    cout << endl;
  }
}