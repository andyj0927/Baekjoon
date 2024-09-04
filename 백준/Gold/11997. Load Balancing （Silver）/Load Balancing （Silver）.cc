#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector <int> xaxis(n),yaxis(n);
  vector <pii> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i].first >> a[i].second;
    xaxis[i] = a[i].first;
    yaxis[i] = a[i].second;
  }
  sort(xaxis.begin(),xaxis.end());
  sort(yaxis.begin(),yaxis.end());
  xaxis.erase(unique(xaxis.begin(),xaxis.end()),xaxis.end());
  yaxis.erase(unique(yaxis.begin(),yaxis.end()),yaxis.end());
  vector <int> cnt(yaxis.size(),0);
  for(int i=0;i<n;i++){
    int idx = lower_bound(yaxis.begin(),yaxis.end(),a[i].second)-yaxis.begin();
    cnt[idx]++;
  }
  for(int i=1;i<yaxis.size();i++){
    cnt[i]+=cnt[i-1];
  }
  sort(a.begin(),a.end());
  int ans = n;
  for(int i=0;i<yaxis.size();i++){
    int idx = 0, lb = cnt[i], hb = cnt[yaxis.size()-1]-cnt[i],lf = 0 ,hf = 0;
    for(int j=0;j<xaxis.size();j++){
      while(idx<n && a[idx].first==xaxis[j]){
        if(a[idx].second<=yaxis[i]){
          lf++;
          lb--;
        }
        else{
          hf++;
          hb--;
        }
        idx++;
      }
      int cur = max({lb,hb,lf,hf});
      ans = min(ans,cur);
    }
  }
  cout << ans << endl;
}