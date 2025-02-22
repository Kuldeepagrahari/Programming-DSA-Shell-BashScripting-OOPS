#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 🔥 Debugging Macros
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

// 🔥 Fast Random Number Generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

// ✅ Brute-Force Solution (Modify this for the given problem)
int brute_force(vector<int>& a) {
    
    // return *max_element(a.begin(), a.end());
}

// ⚡ Optimized Solution (Modify this for the given problem)
int optimized(vector<int>& a) {
  
    // return *max_element(a.begin(), a.end());
}

// 🚀 Stress Testing Function
void stress_test(int test_cases) {
    while (test_cases--) {
        int n = uid(5, 20);  // Generate array size in range [5, 20]
        vector<int> a(n);
        for (int &x : a) x = uid(1, 100);  // Generate array values in range [1, 100]

        // Compute results
        int bf = brute_force(a);
        int opt = optimized(a);

        // Compare outputs
        if (bf != opt) {
            cout << "❌ Test Failed!\n";
            cout << "N = " << n << "\nArray: ";
            for (int x : a) cout << x << " ";
            cout << "\nBrute-Force: " << bf << ", Optimized: " << opt << endl;
            exit(0); // Stop execution on failure
        }
    }
    cout << "✅ All Tests Passed!\n";
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    cout << "Optimized Solution Output: " << optimized(a) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();

    // Run Stress Test
    // stress_test(1000);

    return 0;
}
