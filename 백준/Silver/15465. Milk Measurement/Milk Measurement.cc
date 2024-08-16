#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
int a[101][3];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector <int> milk(3,0);
  for(int i=0;i<n;i++){
    int d;
    string s,s1;
    cin >> d >> s >> s1;
    int val;
    if(s1[0]=='+'){
      val = s1[1]-'0';
    }
    else{
      val = -1*(s1[1]-'0');
    }
    if(s=="Bessie") a[d][0]=val;
    if(s=="Elsie") a[d][1]=val;
    if(s=="Mildred") a[d][2]=val;
  }
  int tot = 7;
  int ans = 0;
  for(int i=1;i<=100;i++){
    int cur = 0;
    for(int j=0;j<3;j++){
      milk[j]+=a[i][j];
    }
    if(milk[0]>=milk[1] && milk[0]>=milk[2]) cur+=1;
    if(milk[1]>=milk[0] && milk[1]>=milk[2]) cur+=2;
    if(milk[2]>=milk[0] && milk[2]>=milk[1]) cur+=4;
    if(cur!=tot){
      ans++;
      tot=cur;
    }
  }
  cout << ans;
}