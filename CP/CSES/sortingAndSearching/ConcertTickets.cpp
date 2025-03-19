
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a)         \
    cout << #a << " = ";  \
    for (auto x : a)      \
        cout << x << " "; \
    cout << "\n";

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

int brute_force(vector<int> &a)
{
}

void optimized(vector<int> &a, vector<int> &b)
{
    // kyuki hame less than equal chahiye isliye , hum pehle upperbound nikaalenge jisse ye confirm ho jaye ki hame jo chahiye usse just badi value ho aur just usse pehle itr par ayenge to hame jo chahiye vo mil jaega
    //isse alag se new lower bound function nhi likhna padega
    int n = a.size(), m = b.size();
    multiset<int> ms;
    for(auto x: a) ms.insert(x);
    for(int i = 0; i < m; i++){
      auto it = ms.upper_bound(b[i]);
      if(it == ms.begin()){
        //not present in ms
        cout << "-1\n";
      }else{
        it--;
        cout << *it << endl;
        ms.erase(it);
      }
    }

    
}

// void stress_test(int test_cases) {
//     while (test_cases--) {
//         int n = uid(5, 20);
//         vector<int> a(n);
//         for (int &x : a) x = uid(1, 100);

//         int bf = brute_force(a);
//         int opt = optimized(a);

//         if (bf != opt) {
//             cout << "Test Failed!\n";
//             cout << "N = " << n << "\nArray: ";
//             for (int x : a) cout << x << " ";
//             cout << "\nBrute-Force: " << bf << ", Optimized: " << opt << endl;
//             exit(0);
//         }
//     }
//     cout << "All test Passed\n";
// }

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> pt(n);
    for (int &x : pt)
        cin >> x;
    vector<int> mpc(m);
    for (int &x : mpc)
        cin >> x;

    optimized(pt, mpc);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    // Run Stress Test
    // stress_test(1000);

    return 0;
}
