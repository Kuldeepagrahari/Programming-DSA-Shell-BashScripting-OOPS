#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int Sam(vector<int> &dp, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    long long t = 0;
    if (dp[n] != -1)
        return dp[n];

    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        {
            long long t2 = Sam(dp, n - i) % MOD;
            t = (t + t2) % MOD;
        }
    }
    return dp[n] = t;
}
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << Sam(dp, n) % MOD << endl;
}