#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int num = 0;
    int dig = 0;
    for(int i = 0; i < s.length(); i++) {
        dig = s[i] - '0';
        num += dig;
        num *= 10;
    }
    num /= 10;
    int sq = sqrt(num);
    int val1 = sq - 1;
    int val2 = 1;
    if(sq * sq == num) {
        if(sq == 0) cout << "0" << " " << "0\n";
        else
         cout << val1 << " " << val2 << "\n";
    } else {
        cout << "-1\n";
    }
}
int main(){
     int t;
     cin >> t;
     while(t--) solve();
}