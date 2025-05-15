#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int ns = s.size(), nt = t.size();
        int i = 0, j = 0;
        while (i < ns & j < nt)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                break;
        }
        int ans = (ns - i) + (nt - j);
        if(i > 0)
           ans += i + 1;
        cout << ans << endl;
    }
}