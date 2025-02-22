#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{

    int n, k;
    cin >> n >> k;

    vector<pair<int, string>> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back({s.length(), s});
    }
    sort(v.begin(), v.end());
    string tar;
    cin >> tar;
    int tarl = tar.length();

    int delay = 0;
    int attempt = 0;
    int best, worst;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first == tarl)
        {
            best = delay + 1;

            for (int j = i; j < n; j++)
            {
                
                if (j == n - 1)
                {
                    worst = delay + 1;
                    break;
                }
                else if (v[j + 1].first != tarl)
                {
                    worst = delay + 1;
                    break;
                }
                delay += 1;
                attempt++;
                if (attempt == k)
                {
                    delay += 7;
                    attempt = 0;
                }
            }
            break;
        }
        delay += 1;
        attempt++;
        if (attempt == k)
        {
            delay += 7;
            attempt = 0;
        }
    }
    cout << best << " " << worst << endl;
}