#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";


void solve() {
    int n, m;
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i = 0; i < n ; i ++){
        //duration, deadline
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end());
    ll ans = 0;
    ll finish = 0;
    for (int i = 0; i < n; i ++){
      finish += vp[i].first;
      ll deadline = vp[i].second;
      ans += (deadline - finish);

    }
    cout << ans << endl;
    // for (int &x : a) cin >> x;
    
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}
