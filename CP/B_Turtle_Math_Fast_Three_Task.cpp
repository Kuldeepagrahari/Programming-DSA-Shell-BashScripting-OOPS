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
        cin >> n;
        int v[n];
        int sum = 0;
        int f = 0;
        for ( int i = 0; i < n ;i ++ ){ 
            cin >> v[i];
            sum += abs (v[i]);
            if ( v[i] % 3 == 1 ) f = 1;
          
        }

        if ( sum % 3 == 0 ) cout << "0\n";
        else if ( sum % 3 == 2 ) cout << "1\n";
        else 
        if ( f == 1 ) cout << "1\n";
        else cout << "2\n";

        // cout << sum << endl;
       
        




        } 
}