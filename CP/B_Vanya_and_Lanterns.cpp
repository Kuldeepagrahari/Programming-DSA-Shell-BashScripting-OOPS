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
   
        int n , k , x;
        cin >> n >> k ;
        int v[n];
        for ( int i = 0; i < n ;i ++ )cin >> v[i];
        sort ( v,v + n) ;
        double maxDif = v[0] - 0;
        for ( int i = 0; i < n - 1 ; i ++ ){
            double dif = double( v[i+1] - v[i] )/2;
            
            maxDif = max ( maxDif, dif );
        }
        double last = k - v[n-1];
       maxDif = max ( maxDif, last);
        cout << fixed << setprecision(10) << maxDif << endl;

        
    
}