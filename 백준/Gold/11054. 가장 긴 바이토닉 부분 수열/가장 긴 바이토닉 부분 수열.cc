#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n+1);
    vector <int> d(n+1,1);
    vector <int> dd(n+1,1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i =1;i<=n;i++){
        for(int j =1; j<i;j++){
            if(a[i]>a[j]&& d[i]<=d[j]){
                d[i] = d[j]+1;
            }
        }
    }
    for(int i =n;i>=1;i--){
        for(int j =n; j>=i;j--){
            if(a[i]>a[j]&& dd[i]<=dd[j]){
                dd[i] = dd[j]+1;
            }
        }
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ans<d[i]+dd[j]&& a[i]!=a[j]){
                ans = d[i]+dd[j];
            }
        }
    }
    cout << ans;

}