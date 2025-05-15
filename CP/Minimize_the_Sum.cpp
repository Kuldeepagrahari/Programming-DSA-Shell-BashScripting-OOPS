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
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i ++){
       for(int j = 0; j < n; j++){
              cin >> v[i][j];
       }
    }

    int maxi = 0;
    int mini = INT_MAX;
    for(int i = 0; i < n; i ++){
       for(int j = 0; j < n; j++){
             maxi = max(maxi, v[i][j]);
             mini = min(mini, v[i][j]);
       }
    }
    

    int low = mini, high = maxi;
    int ans = maxi;
    int score = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        int F1 = 0;
    
        for (int i = 0; i < n; i++) {
            F1 += min(v[0][i], mid);
        }
    
        for (int i = 1; i < n; i++) {
            int Fi = 0;
            for (int j = 0; j < n; j++) {
                Fi += min(v[i][j], mid);
            }
            if (Fi > F1) cnt++;
        }
    
        if (cnt > score) {
            score = cnt;
            ans = mid;
            high = mid - 1;
        } else if (cnt == score) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
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
