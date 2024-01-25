#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool compare(const tuple<int,int,string> &a, const tuple<int,int,string> &b){
  if( get<0>(a)== get<0>(b)){
    return get<1>(a) < get<1>(b);
  }
  return get<0>(a)<get<0>(b);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int cnt[201]={0,};
  vector <tuple<int,int,string>> a(n);
  for(int i=0;i<n;i++){
    int x;
    string s;
    cin >> x >> s;
    a[i] = make_tuple(x,cnt[x],s);
    cnt[x]++;

  }
  sort(a.begin(),a.end(),compare);
  for(int i=0;i<n;i++){
    cout << get<0>(a[i]) << " "<< get<2>(a[i])<< endl;
  }
}  