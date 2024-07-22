#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int a[1001][3];
int d[1001][3][3];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<=1000;i++){
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            d[i][j][k] = 1000*1000+1;
        }
    }
}
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    d[1][0][0] = a[1][0];
    d[1][1][1] = a[1][1];
    d[1][2][2] = a[1][2];
    d[2][0][1] = a[1][0]+a[2][1];
    d[2][0][2] = a[1][0]+a[2][2];
    d[2][1][0] = a[1][1]+a[2][0];
    d[2][1][2] = a[1][1]+a[2][2];
    d[2][2][0] = a[1][2]+a[2][0];
    d[2][2][1] = a[1][2]+a[2][1];

    for(int i=3;i<=n;i++){
        d[i][0][0] = min(d[i-1][0][1],d[i-1][0][2]) +a[i][0];
        d[i][0][1] = min(d[i-1][0][0],d[i-1][0][2]) +a[i][1];
        d[i][0][2] = min(d[i-1][0][0],d[i-1][0][1]) +a[i][2];
        d[i][1][0] = min(d[i-1][1][1],d[i-1][1][2]) +a[i][0];
        d[i][1][1] = min(d[i-1][1][0],d[i-1][1][2]) +a[i][1];
        d[i][1][2] = min(d[i-1][1][0],d[i-1][1][1]) +a[i][2];
        d[i][2][0] = min(d[i-1][2][1],d[i-1][2][2]) +a[i][0];
        d[i][2][1] = min(d[i-1][2][0],d[i-1][2][2]) +a[i][1];
        d[i][2][2] = min(d[i-1][2][0],d[i-1][2][1]) +a[i][2];
    }
    int ans=1000*1000+1;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i!=j && d[n][i][j]< ans){
                ans =d[n][i][j];
            }
        }
    }
    cout << ans;


}