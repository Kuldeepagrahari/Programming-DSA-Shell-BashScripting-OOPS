#include <bits/stdc++.h>
using namespace std;

int Sam(vector<vector<int>> &dp, int ind1, int ind2, string &a, string &b, string &c)
{
    if (ind1 == a.length() && ind2 == b.length())
    {
        return 0;
    }

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int t1 = INT_MAX, t2 = INT_MAX;
    int ccl = ind1 + ind2;
    if (ind1 != a.length())
    {
        
        if (a[ind1] != c[ccl])
        {
            t1 = 1 + Sam(dp, ind1 + 1, ind2, a, b, c);
        }
        else
            t1 = Sam(dp, ind1 + 1, ind2, a, b, c);
        
    }
    if (ind2 != b.length())
    {
        
        if (b[ind2] != c[ccl])
        {
            t2 = 1 + Sam(dp, ind1, ind2 + 1, a, b, c);
        }
        else
            t2 = Sam(dp, ind1, ind2 + 1, a, b, c);
        
    }

    return dp[ind1][ind2] = min(t1, t2);
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;

        cin >> a >> b >> c;
        int la = a.length(), lb = b.length(), lc = c.length();
        vector<vector<int>> dp(la + 1, vector<int>(lb + 1, -1));
        cout << Sam(dp, 0, 0, a, b, c) << endl;
    }
}