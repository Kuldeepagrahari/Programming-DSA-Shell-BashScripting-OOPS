#include <bits/stdc++.h>
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
       while ( t-- ){
       int n , k;

       cin >> n >> k;
       int ans = 0;
       if ( k == 1 ) {ans = 1; k = 2;}

       while ( n != 0 ){
           if ( n == 1 || n < k){
             ans++;
             break;
           }
           if ( ( n & 1 )  && ( k & 1 ) ){
               k++;
               ans +=2;
               n /= k;

           }
           else if ( ( n % 2 == 0 )  && ( k % 2 == 0 ) ){
             k++;
               ans += 2;
               n /= k;
           }
           else {
              ans ++;
              n /= k;
           }
       }
       cout << ans << endl;




    }

}


