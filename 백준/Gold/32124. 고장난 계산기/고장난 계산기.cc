#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,p;
  cin >> n >> p;
  string s,t;
  cin >> s;
  t="";
  stack <int> st;
  map <int,int> mp_findfr, mp_findba;
  int bef= -1;
  for(int i=0;i<n;i++){
    if(s[i]>='0' && s[i]<='9'){
      if(bef==-1){
        bef = i;
      }
    }
    else{
      if(bef!=-1){
        mp_findfr[i-1] = bef;
        mp_findba[bef] = i-1;
      }
      bef = -1;
    }
    if(s[i]=='('){
      st.push(i);
    }
    if(s[i]==')'){
      mp_findfr[i] = st.top();
      mp_findba[st.top()] = i;
      st.pop();
    }
  }
  if(bef!=-1){
    mp_findfr[n-1] = bef;
    mp_findba[bef] = n-1;
  }
  vector <int> a(n+1,0);
  for(int i=0;i<n;i++){
    if(s[i]=='*'){
      int j = i-1;
      if(mp_findfr.find(j)!=mp_findfr.end()){
        j = mp_findfr[j];
      }
      a[j]++;
      int k = i+1;
      if(mp_findba.find(k)!=mp_findba.end()){
        k = mp_findba[k];
      }
      a[k+1]--;
      mp_findfr[k] = j;
    }
  }
  for(int i=0;i<=n;i++){
    if(a[i]>0){
      for(int j=0;j<a[i];j++) t+="(";
    }
    else if (a[i]<0){
      for(int j=0;j<abs(a[i]);j++) t+=")";
    }
    if(i!=n){
      t+=s[i];
    }
  }
  cout << t.length() << endl;
  cout << t << endl;
}