#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MAXN = 1e7;
const ll MOD = 1e9+7;
void solve(){
  int n,c,p;
  vector <string> noun,iverb,verb,conj;
  int num_n=0,num_v=0,num_iv=0,num_conj=0;
  cin >> n >> c >> p;
  for(int i=0;i<n;i++){
    string w, s;
    cin >> s >> w;
    if(w=="noun"){
      num_n++;
      noun.push_back(s);
    }
    if(w=="transitive-verb"){
      num_v++;
      verb.push_back(s);
    }
    if(w=="intransitive-verb"){
      num_iv++;
      iverb.push_back(s);
    }
    if(w=="conjunction"){
      num_conj++;
      conj.push_back(s);
    }
  }
  num_conj = min(num_conj,p);
  int m = num_conj+p;
  int ans = 0, ans_v=0 , ansiv=0,usedcon=0, usedcomma=0, usedpr=0;
  for(int i=1;i<=min(m,num_iv+num_v);i++){
    for(int j=0;j<=min(num_iv,m);j++){
      int curn = j + (i-j)*2;
      if(i-j<0 || (i-j)>num_v) continue;
      if(curn>num_n) continue;
      int curuse = curn;
      curuse+= i;
      curuse+=min(i/2,num_conj);
      if(i-j>0) curuse+=min(num_n-curn,c);
      if(curuse>ans){
        ans = curuse;
        ans_v = (i-j);
        ansiv = j;
        usedcon = min(i/2,num_conj);
        if(i-j>0) usedcomma=min(num_n-curn,c);
        else usedcomma = 0;
        usedpr = i-usedcon;
      }
    }
  }
  cout << ans <<endl;
  if(ans==0){
    cout << endl;
    return;
  }
  int nounidx = 0, vidx=0, ividx=0;
  for(int i=0;i<usedpr;i++){
    if(i!=0) cout << " ";
    cout << noun[nounidx] << " ";
    nounidx++;
    if(vidx<ans_v){
      cout << verb[vidx] << " ";
      vidx++;
      cout << noun[nounidx];
      nounidx++;
      if(usedcomma>0){
        while(usedcomma--){
          cout << ", ";
          cout << noun[nounidx];
          nounidx++;
        }
      }
    }
    else{
      cout << iverb[ividx];
      ividx++;
    }
    if(i<usedcon){
      cout << " " << conj[i] << " ";
      cout << noun[nounidx] << " ";
      nounidx++;
      if(vidx<ans_v){
        cout << verb[vidx] << " ";
        vidx++;
        cout << noun[nounidx];
        nounidx++;
      }
      else{
        cout << iverb[ividx];
        ividx++;
      }
    }
    cout <<".";
  }
  cout << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int repeat;
  cin >> repeat;
  while(repeat--){
    solve();
  }
}