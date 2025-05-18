#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> suf(n + 1, 0);
    for(int i = n - 1; i >= 0; i--){
        suf[i] = suf[i + 1] + v[i];
    }
    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += v[i] * (suf[i + 1] - suf[n]);
    }
    cout << ans << endl;


}