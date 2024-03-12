#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int const MAXN = 1e6+5;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <int> pos,neg;
  int zero = 0 , one = 0;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(x==0){
      zero++;
    }
    else if(x==1){
      one++;
    }
    else if(x>0){
      pos.push_back(x);
    }
    else{
      neg.push_back(x);
    }
  }
  sort(pos.begin(),pos.end(),greater<>());
  sort(neg.begin(),neg.end());
  int ans = 0;
  for(int i=0;i<pos.size();i=i+2){
    if(i+1<pos.size()){
      ans+=(pos[i]*pos[i+1]);
    }
    else{
      ans+=pos[i];
    }
  }
  for(int i=0;i<neg.size();i=i+2){
    if(i+1<neg.size()){
      ans+=(neg[i]*neg[i+1]);
    }
    else{
      if(!zero){
        ans+=neg[i];
      }
    }
  }
  cout << ans+one;

}  