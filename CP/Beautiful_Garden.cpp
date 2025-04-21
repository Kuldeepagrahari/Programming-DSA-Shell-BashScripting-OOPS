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
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);

    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    int m = n - k;

    int plucks = 0;
    for(int i =0 ; i < m; i++) {
        if(d % a[i] == 0){
            plucks += d / a[i];
        }else
        plucks += d / a[i] + 1;
    }
    cout << plucks << endl;
   
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
