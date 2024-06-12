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
// --------------------------------------------------
template <typename Container>
void pairprint(const Container &container)
{

    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

int LO(vector<int> &nums, int target, int l, int r)
{

    int lo = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            lo = mid;
            l = mid + 1;
        }
        else if (nums[mid] > target)
        {

            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return lo;
}
int FO(vector<int> &nums, int target, int l, int r)
{

    int fo = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            fo = mid;
            r = mid - 1;
        }
        else if (nums[mid] > target)
        {

            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return fo;
}

// ------------------------ lets begin sam --------------
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        int x, y, a, b, c, d, m, n;

        cin >> n;
        vector<pair<int, int>> v;

        for ( int i = 0; i < n; i++ ){
            int a, b;
            cin >> a >> b;

            v.push_back({a,b});
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; i ++ ){
            for ( int j =  i + 1 ; j < n ; j++ ){
                ans = max ( ans, v[i].first*v[j].second + v[j].first*v[i].second );
            }
        }

        cout << ans << endl;


        // printer(v);
        // pairprint(v);
    }
}