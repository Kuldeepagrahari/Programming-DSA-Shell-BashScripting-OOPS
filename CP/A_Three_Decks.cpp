#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        if(sum % 3 != 0) {
            cout << "NO\n";
        }else{
            int mean = (a + b + c) / 3;
            if(a > mean || b > mean) cout << "NO\n";
            else cout << "YES\n";
        }
       

    }
}