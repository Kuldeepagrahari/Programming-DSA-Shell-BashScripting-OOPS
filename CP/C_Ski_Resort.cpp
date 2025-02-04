#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> temp(n);
        for (int i = 0; i < n; i++)
            cin >> temp[i];
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (temp[i] <= q)
                cnt++;
            else
            {
                if (cnt >= k)
                {
                    cnt -= (k-1);
                    ans += ((cnt + 1) * cnt) / 2;
                   
                }
                cnt = 0;
            }
        }
        if (cnt >= k)
        { 
            cnt -= (k-1);
            ans += ((cnt + 1) * cnt) / 2;
          
        }
        cout << ans << endl;
    }
}