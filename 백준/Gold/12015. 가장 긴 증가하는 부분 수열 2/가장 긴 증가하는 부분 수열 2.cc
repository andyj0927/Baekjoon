#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[1000005];
int x[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fill(x,x+n+2,1000005);
    x[0]=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int low=0;
        int high = i+1;
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            if(x[mid]<a[i]){
                ans = max(ans,mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        x[ans+1] = min(x[ans+1],a[i]);
    }
    if(n==1){
        cout << 1;
        return 0;
    }
    for(int i=1;i<=n+1;i++){
        if(x[i]==1000005){
            cout << i-1;
            break;
        }
    }
}