#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

// 🔥 Fast Random Number Generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }


// int brute_force(vector<int>& a) {
    
   
// }


void optimized(vector<int>& a, int ind, ll sum, ll sub_sum, ll &ans) {
    //solve here
    if ( ind == a.size() ){
        ans = min(ans, abs(2*sub_sum - sum));
        return;
    }
    int t = 0, nt = 0;
    sub_sum += a[ind];
    optimized(a, ind + 1, sum, sub_sum, ans);
    sub_sum -= a[ind];
    optimized(a, ind + 1, sum, sub_sum, ans);
    
    
   
}



// void stress_test(int test_cases) {
//     while (test_cases--) {
//         int n = uid(5, 20); 
//         vector<int> a(n);
//         ll sum = 0;
//         for (int &x : a) {x = uid(1, 100);  sum += x;}
//         ll bf = INT_MAX, opt = INT_MAX;
//         brute_force(a, 0, sum, 0, bf);
//         optimized(a, 0, sum, 0, opt);
//         cout << bf << " " << opt << endl;
      
//         if (bf != opt) {
//             cout << "❌ Test Failed!\n";
//             cout << "N = " << n << "\nArray: ";
//             for (int x : a) cout << x << " ";
//             cout << "\nBrute-Force: " << bf << ", Optimized: " << opt << endl;
//             exit(0); 
//         }
//     }
//     cout << " All Tests Passed!\n";
// }


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int &x : a){
        cin >> x;
        sum += x;
    }
   
    ll ans = INT_MAX;
    optimized(a, 0, sum, 0, ans);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // stress_test(1000);

    return 0;
}
