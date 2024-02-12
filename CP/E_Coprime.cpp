#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
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
    int n;
    cin >> n;
    int v[n];
    unordered_map < int ,int> mp;
    
    for ( int i = 0; i < n; i++ ){
        cin >> v[i];
        mp[v[i]]++;
    }
    sort ( v ,v+n );
    int gcd = v[0];
    for ( int i = 1; i < n; i++ ){
        gcd = __gcd( gcd, v[i] );
    }
    

    
    if ( gcd == 1 ){
        
        bool flag = true;
        for ( int i = 2; i<= 1e6; i++ ){
            int cnt = 0;
            for ( int j = 1; j * i <= 1e6; j++ ){
                cnt += mp[j*i];
                 if ( cnt == 2 ){
                flag = false;
                break;
            }
            if ( !flag) break;
            }
           
        }

        
         if ( flag ) cout << "pairwise coprime\n";
         else cout << "setwise coprime\n";
    }
    else cout << "not coprime\n";
}