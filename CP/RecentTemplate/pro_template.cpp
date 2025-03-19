#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

int brute_force(vector<int>& a) {
}

int optimized(vector<int>& a) {
}

void stress_test(int test_cases) {
    while (test_cases--) {
        int n = uid(5, 20);  
        vector<int> a(n);
        for (int &x : a) x = uid(1, 100); 

      
        int bf = brute_force(a);
        int opt = optimized(a);

        if (bf != opt) {
            cout << "❌ Test Failed!\n";
            cout << "N = " << n << "\nArray: ";
            for (int x : a) cout << x << " ";
            cout << "\nBrute-Force: " << bf << ", Optimized: " << opt << endl;
            exit(0); 
        }
    }
    cout << "All test Passed\n";
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    cout << optimized(a) << "\n";
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
