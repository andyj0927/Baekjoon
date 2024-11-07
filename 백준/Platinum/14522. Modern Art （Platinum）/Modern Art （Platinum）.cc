#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 4e6;
const ll INF = 1e10;
ll n;
ll board[1001][1001],pre[1002][1002];
int idx[1000001][4]; 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) cin >> board[i][j];
  }
  for(int i=1;i<=n*n;i++){
    idx[i][0] = -1;
    idx[i][1] = -1;
    idx[i][2] = -1;
    idx[i][3] = -1;
  }
  int count = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(board[i][j]){
        int cur = board[i][j];
        if(idx[cur][0]==-1){
          count++;
          idx[cur][0]=i;
          idx[cur][1]=i;
          idx[cur][2]=j;
          idx[cur][3]=j;
        }
        else{
          idx[cur][0]=min(i,idx[cur][0]);
          idx[cur][1]=max(i,idx[cur][1]);
          idx[cur][2]=min(j,idx[cur][2]);
          idx[cur][3]=max(j,idx[cur][3]);
        }
      }
    }
  }
  for(int i=1;i<=n*n;i++){
    if(idx[i][0]==-1) continue;
    pre[idx[i][0]][idx[i][2]]+=i;
    pre[idx[i][1]+1][idx[i][2]]-=i;
    pre[idx[i][0]][idx[i][3]+1]-=i;
    pre[idx[i][1]+1][idx[i][3]+1]+=i;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) pre[i][j]+=(pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]);
  }
  if(count==1){
    if(n==1) cout << 1 << endl;
    else cout << n*n-1 << endl;
    return 0;
  }
  vector <int> check(n*n+1,1);
  int ans = n*n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(pre[i][j]!=board[i][j] && check[board[i][j]]){
        ans--;
        check[board[i][j]] = 0;
      }
    }
  }
  cout << ans;
}  