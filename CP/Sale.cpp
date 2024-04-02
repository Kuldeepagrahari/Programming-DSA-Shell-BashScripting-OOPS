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
       for ( int i = 0; i < n ; i++ ){
        cin >> v[i];
       }
        
        int maxi = 0;
        int sum = 0;
        for ( int i = 0; i < n ; i++ ){

            sum += v[i];
            maxi = max ( maxi , sum+v[i]);
        }

        cout << maxi << endl;
       
        




        } 
}