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

void solve()
{
    int n, m;
    cin >> n;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;
    int mx_odd = 0, mx_even = 0;
    int sum_even = 0, sum_odd = 0;
    int odds = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & 1)
            mx_odd = max(mx_odd, a[i]), sum_odd += a[i], odds++;
        if (a[i] % 2 == 0)
            mx_even = max(mx_even, a[i]), sum_even += a[i];
    }
    // take from rest od the odds into evens
    int extra = sum_odd - mx_odd - odds + 1;
    if (mx_even == 0 || mx_odd == 0)
        cout << max(mx_even, mx_odd) << endl;
    else
        cout << mx_odd + sum_even + extra << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
