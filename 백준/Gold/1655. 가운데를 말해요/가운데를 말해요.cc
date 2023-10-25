#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

priority_queue<int,vector<int>> maxq;
priority_queue<int,vector<int>,greater<int>> minq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        if(maxq.size()==minq.size()){
            maxq.push(t);
        }
        else{
            minq.push(t);
        }
        if(!maxq.empty()&&!minq.empty()&&maxq.top()>minq.top()){
            int a = maxq.top();
            int b = minq.top();
            maxq.pop();
            minq.pop();
            maxq.push(b);
            minq.push(a);
        }
        cout << maxq.top() << endl;
    }

}