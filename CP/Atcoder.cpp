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
const int C = 1e9;
vector<int> a(1000001, 0);
vector<int> pre(1000001, 0);
void solve()
{
    int n, k;
    cin >> n >> k;
    // vector<int> a(n + 1, 0);
    // vector<int> pre(n + 2, 0);

    if (k >= n)
    {
        cout << "1\n";
        return;
    }

    for (int i = 0; i < k; i++)
    {
        a[i] = 1;
        pre[i + 1] = pre[i] + 1;
    }

    
    a[k] = k % C;
    pre[k + 1] = 2 * pre[k];
 
    int j = 1;
    for (int i = k + 1; i <= n; i++)
    {
        a[i] = (pre[i] - pre[j++]) % C;
        pre[i + 1] = (pre[i] + a[i]);
    }
    int ans = a[n] % C;
    cout << ans << endl;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
