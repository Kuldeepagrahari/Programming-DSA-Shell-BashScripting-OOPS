#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 10;
vector<bool> prime(N, 1);

vector<vector<vector<ll>>> dp;
#define pi pair<int, int>

int solve(int i, int k, vector<int> &arr, int pre)
{

    if (i >= arr.size() || k == 0)
        return 0;

    if (dp[i][k][pre + 1] != -1)
        return dp[i][k][pre + 1];
    int nt = 0, t = 0;

    nt = solve(i + 1, k, arr, pre);

    if (pre == -1)
    {
        t = solve(i + 1, k - 1, arr, arr[i]);
    }
    else
        t = (pre + arr[i]) + solve(i + 1, k - 1, arr, arr[i]);

    return dp[i][k][pre + 1] = max(t, nt);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        dp.resize(n + 1, vector<vector<ll>>(k + 1, vector<ll>(55, -1)));
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        ll ans = solve(0, k, arr, -1);
        cout << ans << endl;
    }
}