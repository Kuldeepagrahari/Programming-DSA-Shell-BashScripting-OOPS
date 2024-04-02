#include <bits/stdc++.h>
#include <algorithm>
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
signed main(){
        
        int t;
        cin >> t;
        while ( t-- ){
        int n , k , m;
        cin >> n >> m >> k;
        int v[n];
        int v2[m];
        for ( int i = 0; i < n ;i ++ ){ 
            cin >> v[i];
          
        }
       
        for ( int i = 0; i < m ;i ++ ){ 
            cin >> v2[i];
          
        }
        sort ( v,v+n);
        sort ( v2,v2+m);
        int ans = 0;
        for ( int i = 0; i< n ;i ++ ){
            int ind = upper_bound( v2,v2+m, k - v[i] ) -v2;
            ans += ind;
        }
        cout << ans << endl;





        } 
}