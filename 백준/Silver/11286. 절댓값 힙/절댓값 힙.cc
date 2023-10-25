#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


struct cmp{
    bool operator()(int a,int b){
        if(abs(a)==abs(b)){
            return a>b;
        }
        else{
            return abs(a)>abs(b);
        }
    }
};
priority_queue<int,vector<int>,cmp> q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if(t==0){
            if(!q.empty()){
                cout << q.top() << endl;
                q.pop();
            }
            else{
                cout << 0 << endl;
            }
        }
        else{
            q.push(t);
        }
    }
}