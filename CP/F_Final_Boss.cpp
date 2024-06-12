#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int h, n;
        cin >> h >> n;

        vector<int> damage(n);
        vector<int> cooldown(n);

        for (int i = 0; i < n; ++i) {
            cin >> damage[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> cooldown[i];
        }

        vector<int> next_available(n, 0);
        int current_time = 0;
        int turns = 0;

        while (h > 0) {
            turns++;
            int total_damage = 0;

            for (int i = 0; i < n; ++i) {
                if (next_available[i] <= current_time) {
                    total_damage += damage[i];
                    next_available[i] = current_time + cooldown[i];
                }
            }

            h -= total_damage;

            // If no attacks were used, find the next available attack
            if (total_damage == 0) {
                current_time = *min_element(next_available.begin(), next_available.end());
            } else {
                current_time++;
            }
        }

        cout << turns << endl;
    }

    return 0;
}
