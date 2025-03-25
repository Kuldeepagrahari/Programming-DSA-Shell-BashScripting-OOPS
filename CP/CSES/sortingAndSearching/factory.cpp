
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
ll predicate(vector<ll> &v, ll time)
{
    ll prod = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        prod += time / v[i];
    }
    return prod;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // [6 15]
    ll mini = *min_element(v.begin(), v.end());
    ll maxi = *max_element(v.begin(), v.end());

    ll l = m / n;
    ll r = m / n;

    if (m % n != 0)
    {
        l++;
        r++;
    }
    l *= mini;
    r *= maxi;
    ll minTime = LLONG_MAX;

    while (r >= l)
    {
        ll time = l + (r - l) / 2;
        ll prod = predicate(v, time);

        if (prod < m)
        {
            l = time + 1;
        }
        else if (prod >= m)
        {
            r = time - 1;
            minTime = time;
        }
    }
    cout << minTime << endl;
    // optimized(pt, mpc);
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
