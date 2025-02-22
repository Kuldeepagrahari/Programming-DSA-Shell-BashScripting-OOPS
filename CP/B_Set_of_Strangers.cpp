#include <bits/stdc++.h>
using namespace std;
#define int long long

// bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
//     if (a.first != b.first)
//         return a.first > b.first;
//     return a.second < b.second;
// }

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n, vector<int>(m));
        vector<int> str(n * m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val = v[i][j];
                int f = 1;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + x[k];
                    int ny = j + y[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        if (v[nx][ny] == val)
                        {
                            f = 2;
                            break;
                        }
                    }
                }
                if (str[val] == 0)
                    str[val] = f;
                else if (str[val] == 1 && f == 2)
                    str[val] = 2;
            }
        }
        int sum = 0;
        int f = 1;
        int f1 = 0;
        for (int i = 0; i < n * m + 1; i++)
        {
            sum += str[i];
            if (str[i] == 2)
                f = 2;
            if (str[i] == 1)
                f1 = 1;
        }
        if (f == 2)
            cout << sum - 2 << endl;
        else if (f1 == 1)
            cout << sum - 1 << endl;
        else
            cout << sum << endl;
        // cout << sum - f << endl;
    }
}
