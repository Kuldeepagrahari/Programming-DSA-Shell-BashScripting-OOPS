
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
template <typename Container>
void printer(const Container &container)
{
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// --------------------------------------------------
template <typename Container>
void pairprint(const Container &container)
{
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}
signed main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> aa(n, -1);
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
  ans += (mp[v[i]]);
            if (v[i] != 1 && (3 * v[i]) % (v[i] - 1) == 0)
            {
                int val = 3 * v[i] / (v[i] - 1);
                mp[val]++;
            }
            // pairprint(mp);
            // cout << v[i] << " ";
          
        }

        cout << ans << endl;
    }
}
