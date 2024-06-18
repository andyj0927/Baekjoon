#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;  
const ll MAXN = 2e5+5;
int dp[10000];
pair<int,char> before[10000];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    for(int i=0;i<10000;i++) dp[i] = -1;
    int a,b;
    cin >> a >> b;
    queue <int> q;
    q.push(a);
    dp[a]=1;
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      int n;
      n = (2*cur)%10000;
      if(dp[n]==-1){
        dp[n] = 1;
        before[n] = {cur,'D'};
        q.push(n);
      }
      n = (cur-1+10000)%10000;
      if(dp[n]==-1){
        dp[n] = 1;
        before[n]={cur,'S'};
        q.push(n);
      }
      int d1 = cur/1000, d2=(cur/100)%10, d3 = (cur/10)%10, d4 = cur%10;
      n = d2*1000+d3*100+d4*10+d1;
      if(dp[n]==-1){
        dp[n] = 1;
        before[n] = {cur,'L'};
        q.push(n);
      }
      n =d4*1000+d1*100+d2*10+d3;
      if(dp[n]==-1){
        dp[n] = 1;
        before[n] = {cur,'R'};
        q.push(n);
      }
    }
    string s = "";
    while(true){
      if(b==a) break;
      s+=before[b].second;
      b = before[b].first;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
  }
}