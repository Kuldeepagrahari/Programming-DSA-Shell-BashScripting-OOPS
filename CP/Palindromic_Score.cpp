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
    int n, k, d, x, y, z;
    cin >> x >> y >> z;

    int a[3] = {x, y, z};
    sort(a, a + 3);
    int ans = a[0] + a[1] ;

    if((a[0] & 1) && (a[1] & 1)) ans --;
    cout << ans << endl;

    // vector<int> a(n);

    // for (int &x : a)
    //     cin >> x;
    // sort(a.begin(), a.end());

   
   
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
