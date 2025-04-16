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
    cin >> n;

    vector<int> a(n);
   

    for (int &it : a)
        cin >> it;
   

    set<int> st;
    int ans = 0;
    set<int> stq;
    for(auto x: a) st.insert(x);
    for(int i = 0; i < n ; i++){
        int q;
        cin >> q;
        st.erase(a[q - 1]);
        if(stq.count(a[q]) == 1) ans+= 0;
        else if(st.count(q) == 1) ans += 2;
        else ans ++;
        cout << ans << " ";
        stq.insert(q);
        
    }
    cout << endl;
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
