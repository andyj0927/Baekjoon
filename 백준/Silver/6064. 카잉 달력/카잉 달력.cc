#include <iostream>
using namespace std;
int main(){
    int t,m,n,x,y;
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        x-=1;
        y-=1;
        bool b= true;
        for(int i=x;i<(n*m);i=i+m){
            if(i%n==y){
                cout << i+1 << '\n';
                b = false;
                break;
            }
        }
        if(b){
            cout << -1 << '\n';
        }
        
    }
}