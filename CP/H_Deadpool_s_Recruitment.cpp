#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
    if (a.first != b.first) 
        return a.first > b.first; 
    return a.second < b.second;  
}

signed main() {
   int n;
    double t1, t2, k;
    cin >> n >> t1 >> t2 >> k;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    vector<pair<double, int>> ans(n);

    for (int i = 0; i < n; i++) {
        double growth1 = t1 * a[i].first * (100 - k) / 100.0 + t2 * a[i].second;
        double growth2 = t1 * a[i].second * (100 - k) / 100.0 + t2 * a[i].first;
        ans[i] = {max(growth1, growth2), i + 1};
    }

    sort(ans.begin(), ans.end(), cmp);

   
    for (int i = 0; i < n; i++)
        cout << ans[i].second << " " << fixed << setprecision(2) << ans[i].first << endl;

}
