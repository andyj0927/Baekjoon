#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector <int> a[1001];
vector <int> b[1001];
int deg[1001];
vector <int> ans;
ll n;
queue <int> q;
map <string,int> mp;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m;
  cin >> n;
  vector <string> name(n);
  for(int i=0;i<n;i++) cin >> name[i];
  sort(name.begin(),name.end());
  for(int i=0;i<n;i++){
    mp[name[i]] = i;
  }
  cin >> m;
  while(m--){
    string s1,s2;
    cin >> s1 >> s2;
    int x = mp[s1], y =mp[s2];
    a[y].push_back(x);
    deg[x]++;
  }
  int cnt = 0;
  for(int i=0;i<n;i++){
    if(deg[i]==0){ q.push(i); cnt++; ans.push_back(i);}
  }
  cout << cnt << endl;
  for(int i=0;i<ans.size();i++){
    cout << name[ans[i]] << " ";
  }
  cout << endl;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : a[cur]){
      deg[i]--;
      if(deg[i]==0){
        b[cur].push_back(i);
        q.push(i);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << name[i] << " " << b[i].size() << " ";
    sort(b[i].begin(),b[i].end());
    for(int j=0;j<b[i].size();j++) cout << name[b[i][j]] << " ";
    cout << endl;
  }
}  