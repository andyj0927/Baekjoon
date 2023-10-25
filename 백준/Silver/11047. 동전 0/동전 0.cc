#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,k;
int a[11];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int i=n-1;
    while(k!=0){
        sum+=(k/a[i]);
        k%=a[i];
        i--;
    }
    cout << sum;
}