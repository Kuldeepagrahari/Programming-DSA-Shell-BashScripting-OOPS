
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
        int n, k, m, a, b;
        cin >> n >> a >> b;
        vector<int> aa(n*n);
        for ( int i = 0 ; i < n * n ; i++ ){
            cin >> aa[i];
        }

        sort ( aa.begin(), aa.end());
        int mini = aa[0];

        int v[n][n];
        v[0][0] = mini;
        for ( int i = 1; i< n ; i++ ){
           v[0][i] = b + v[0][i-1];
        }

        for ( int i = 0; i < n ; i++ ){
            for ( int j = 1; j < n ; j ++ ){
                v[j][i] = v[j-1][i] + a;
            }
        }
         vector<int>ck;
          for ( int i = 0; i < n ; i++ ){
            for ( int j = 0; j < n ; j ++ ){
                // v[j][i] = v[j-1][i] + a;
                ck.push_back(v[i][j]);

            }
        }

        sort ( ck.begin(), ck.end());
        if ( ck == aa ) cout << "YES" << endl;
        else cout << "NO\n";





      
       
    }
}
