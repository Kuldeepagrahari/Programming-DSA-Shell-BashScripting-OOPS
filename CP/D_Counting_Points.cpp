#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    long long count = 0;
    vector<pair<int, int>> intervals;

    for (int y = -m; y <= m; y++) {
        intervals.clear();
        for (int i = 0; i < n; i++) {
            long long r_squared = (long long)r[i] * r[i];
            long long y_squared = (long long)y * y;

            if (r_squared - y_squared >= 0) {
                int dx = (int)sqrt(r_squared - y_squared);
                intervals.emplace_back(x[i] - dx, x[i] + dx);
            }
        }

        sort(intervals.begin(), intervals.end());

        long long current_start = -2e9 - 1;
        long long current_end = -2e9 - 1;

        for (const auto& interval : intervals) {
            if (interval.first > current_end) {
                if(current_end >= current_start){
                  count += (current_end - current_start + 1);
                }
                current_start = interval.first;
                current_end = interval.second;
            } else {
                current_end = max(current_end, interval.second);
            }
        }
        if(current_end >= current_start){
            count += (current_end - current_start + 1);
        }
    }

    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}