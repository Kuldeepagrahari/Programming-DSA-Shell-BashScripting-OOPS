#include <bits/stdc++.h>
using namespace std;

// 🔥 Random number generator (Better than rand())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

// ✅ Brute Force (O(N²))
int brute_force(vector<int> &a, int k) { 
    int n = a.size(), max_length = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum <= k) max_length = max(max_length, j - i + 1);
            else break;
        }
    }
    return max_length;
}

// ⚡ Optimized Sliding Window (O(N))
int optimized(vector<int> &a, int k) {
    int n = a.size(), max_length = 0, left = 0;
    long long sum = 0;
    for (int right = 0; right < n; right++) {
        sum += a[right];
        while (sum > k) {
            sum -= a[left];
            left++;
        }
        max_length = max(max_length, right - left + 1);
    }
    return max_length;
}

int main() {
    while (true) {
        int n = uid(5, 15);  // Small test cases first
        int k = uid(10, 50); // Random K value
        vector<int> a(n);
        for (int &x : a) x = uid(1, 20);  // Random numbers in range [1, 20]

        int bf = brute_force(a, k);
        int opt = optimized(a, k);

        if (bf != opt) {
            cout << "❌ Test Failed!\n";
            cout << "N = " << n << ", K = " << k << "\nArray: ";
            for (int x : a) cout << x << " ";
            cout << "\nBrute-Force: " << bf << ", Optimized: " << opt << endl;
            break;
        }
    }
    return 0;
}
