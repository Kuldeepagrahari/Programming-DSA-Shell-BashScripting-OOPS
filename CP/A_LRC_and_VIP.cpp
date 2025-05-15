#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int mx = *max_element(v.begin(), v.end());
    int gcd = 0;
    for(int i = 0; i < n; i++){
        if(v[i] != mx){
            gcd = __gcd(gcd, v[i]);
        }
    }
    if(gcd == mx || gcd == 0) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            if(v[i] == mx) cout << "1 ";
            else cout << "2 ";
        }
        cout << "\n";
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}