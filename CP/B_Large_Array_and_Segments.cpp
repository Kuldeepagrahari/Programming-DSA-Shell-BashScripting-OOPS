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
    int n, x, k;
    cin >> n >> k >> x;

    vector<int> a(n);

    for (int &it : a)
        cin >> it;
        // vdebug(a);
    int sum = 0;
    for (int i = 0; i <  n; i++)
        sum += a[i];

    int tot = sum * k;

    if (tot < x)
    {
        cout << "0\n";
        return;
    }
    int c = 0;
    int sum2 = sum;
    for (int i = 0; i < k; i++)
    {
        if (sum2 >= x)
        {
            break;
        }
        sum2 += sum;
        c++;
    }
    int ans = 0;
    
    // if (sum2 == x)
    // {
    //     ans = (k - c) * n;
    // }

    // else if (sum2 > x)
    // {
        sum2 -= sum;
        ans = (k - c - 1) * n;

        for (int i = n - 1; i >= 0; i--)
        {
            if (sum2 + a[i] >= x)
            {
                ans += i + 1;

                break;
            }
            sum2 += a[i];
        }
    // }
    cout << ans << endl;
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
