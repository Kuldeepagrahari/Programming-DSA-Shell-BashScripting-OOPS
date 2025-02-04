#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    while( t-- ){
        int n;
        cin >> n;

        vector <int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            if ( sum % 2 == 0 ){
               while ( sum % 2 == 0 ){
                sum /= 2;
               }
               ans++;
            }
        }



    }
}