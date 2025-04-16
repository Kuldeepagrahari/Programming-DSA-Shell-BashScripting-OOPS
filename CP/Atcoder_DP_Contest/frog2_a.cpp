#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n";

// Custom hash for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 1);
    }
};

int n, k;
int a[100000 + 1];
const int inf = 1e9 + 8;

// Use custom hash in unordered_map
unordered_map<pair<int, int>, int, pair_hash> mp;

int f(int i, int j) {
    if (j - i > k) return inf;
    if (j > n) return inf;
    if (i >= n) return 0;

    if (mp.count({i, j})) return mp[{i, j}];

    int &ans = mp[{i, j}];
    ans = inf;

    // Try skipping j
    ans = min(ans, f(i, j + 1));

    // Try jumping to j
    if (i != j)
        ans = min(ans, abs(a[i] - a[j]) + f(j, j));

    return ans;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = f(1, 1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}
