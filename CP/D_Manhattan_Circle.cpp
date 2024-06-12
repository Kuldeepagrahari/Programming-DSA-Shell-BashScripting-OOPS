#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename Container>
void printer(const Container &container)
{
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <typename Container>
void pairprint(const Container &container)
{
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

int countLocations(int x, int y, int z, int k)
{
    int max_locations = 0;

    // Iterate over all possible dimensions of the secret box S
    for (int i = 1; i * i * i <= k; ++i)
    {
        if (k % i == 0)
        {
            int volume1 = k / i;
            for (int j = 1; j * j <= volume1; ++j)
            {
                if (volume1 % j == 0)
                {
                    int a = i;
                    int b = j;
                    int c = volume1 / j;
                    if (a <= x && b <= y && c <= z)
                    {
                        max_locations = max(max_locations, (x - a + 1) * (y - b + 1) * (z - c + 1));
                    }
                    if (a <= x && c <= y && b <= z)
                    {
                        max_locations = max(max_locations, (x - a + 1) * (y - c + 1) * (z - b + 1));
                    }
                    if (b <= x && a <= y && c <= z)
                    {
                        max_locations = max(max_locations, (x - b + 1) * (y - a + 1) * (z - c + 1));
                    }
                    if (b <= x && c <= y && a <= z)
                    {
                        max_locations = max(max_locations, (x - b + 1) * (y - c + 1) * (z - a + 1));
                    }
                    if (c <= x && a <= y && b <= z)
                    {
                        max_locations = max(max_locations, (x - c + 1) * (y - a + 1) * (z - b + 1));
                    }
                    if (c <= x && b <= y && a <= z)
                    {
                        max_locations = max(max_locations, (x - c + 1) * (y - b + 1) * (z - a + 1));
                    }
                }
            }
        }
    }

    return max_locations;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<int> ans;

    while (t--)
    {
        int x, y, z, k;
        cin >> x >> y >> z >> k;
        ans.push_back(countLocations(x, y, z, k));
    }

    for (auto x: ans)
    {
        cout << x << endl;
    }

    return 0;
}
