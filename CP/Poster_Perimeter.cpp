#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        int a, b, c, k;
        cin >> a >> b >> k;

        int p = 2*(a + b);

        if ( p >= k ){
            if ( k < 4 ){
                cout << 4 - k << endl;
            }else{
            if ( k& 1 )cout << "1\n";
            else cout << "0\n";}
        }else{
            cout << k - p << "\n";
        }



        

    }
}