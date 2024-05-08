
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

        if ( b > 2*a ){
           cout << n*a << endl;
        }
        else{
           
              int bada = n%2;
            int chota = n - n%2;
            cout << (chota/2)*b + bada*a << endl;
        }
    
        
       
    }
}
