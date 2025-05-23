#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<int> v(n, 0);

    int mn = k * b;
    
    if (s < mn)
    {
        cout << "-1\n";
    }
    else
    { // k*b me (k - 1) add krne se b ki value me fark nhi padega isliye hum v[0] me bhi k - 1 baad me add karenge jisse jada badi range of sum ka ans hum de sake, isliye max jitta hum kisi ai ko de sakte h vo denge aur hamare logic ke hisaab se sirf hum first value se b ki complete value lenge fir bakiyo ko k - 1 ya jitta sum bacha h vo dedenge aur vo b me contribute nhi kar payenge
        v[0] = mn;

        s -= mn;
        for (int i = 0; i < n; i++)
        {
            int cur = min(k - 1, s);
            v[i] += cur;
            s -= cur;
        }
        if (s > 0)
            cout << "-1\n";
        else
        {
            for (int i = 0; i < n; i++)
                cout << v[i] << " ";
            cout << endl;
        }
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}