#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// O(Sum of values * N) = O(10^7)

vector<vector<int>> dp;
// int K(string& s, string &t, int i, int j) {
//     if(i == s.size() || j == t.size()) return 0;

//     if(dp[i][j] != -1) return dp[i][j];
//     int match = 0, notmatch = 0;

//     if(s[i] == t[j]){
//         match = 1 + K(s, t, i + 1, j + 1);
//     }else notmatch = max(K(s, t, i + 1, j), K(s, t, i, j + 1));
//     return dp[i][j] = max(match, notmatch);

// }

signed main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();

    dp.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
            else
            {
                dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }
    int mx_l = dp[n][m];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int matched = 0;
    string LCS = "";

    // bottom up approach
    // jab match hogya to theek h add krlo par agar match nhi hue to ye decide krna h ki s ke char ko rakh kar t ke aage wale char se continue kare ya fir t ke char ko rakhkar s ke aage wale char se continue kare [ jisse longest lcs mil sake] -> ye kaam dp decide krne wala h
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            LCS += s[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
                i--;
        }
    }
    reverse(LCS.begin(), LCS.end());

    cout << LCS << endl;
}
