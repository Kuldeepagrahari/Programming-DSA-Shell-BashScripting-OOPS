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
    int n, m, k;
    cin >> n;
    string s;
    cin >> s;

    int girls = 0, boys = 0;
    for(int i =0 ; i < n; i ++){
        if(s[i] == 'G') girls++;
        else boys++;

        if(2 * girls < boys) break;
    }
    cout << boys + girls << endl;

    // vector<int> a(n);

    // for (int &x : a)
    //     cin >> x;
   
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
