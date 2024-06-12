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

        // Priority queue to manage cooldowns, stores (next_available_turn, damage)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int current_time = 0;
        int turns = 0;

        // Initialize priority queue with all attacks being available at turn 0
        for (int i = 0; i < n; ++i) {
            pq.push({0, i});
        }

        while (h > 0) {
            turns++;
            vector<pair<int, int>> temp;

            // Use all available attacks at the current time
            while (!pq.empty() && pq.top().first <= current_time) {
                int idx = pq.top().second;
                pq.pop();
                h -= damage[idx];
                temp.push_back({current_time + cooldown[idx], idx});
            }

            // Add attacks back to the priority queue with updated cooldowns
            for (auto &it : temp) {
                pq.push({it.first, it.second});
            }

            // If all attacks were on cooldown, skip to the next available turn
            if (temp.empty()) {
                current_time = pq.top().first;
            } else {
                current_time++;
            }
        }

        cout << turns << endl;
    }

    return 0;
}
