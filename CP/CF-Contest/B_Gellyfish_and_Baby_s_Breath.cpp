#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n), q(n), r(n);
        for (int &x : p) cin >> x;
        for (int &x : q) cin >> x;

        vector<int> pow2(2 * n);
        pow2[0] = 1;
        for (int i = 1; i < 2 * n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                mx = max(mx, pow2[p[j] + q[i - j]]);
            }
            r[i] = mx;
        }

        for (int x : r) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
