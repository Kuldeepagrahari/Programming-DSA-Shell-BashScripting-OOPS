#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while ( t--){
        int x,y,a,b,m,n;

        cin >> x >> y;

        int mini  = min ( x,y);
        int maxi = max ( x,y);
        cout << mini << " " << maxi << endl;
    }
}