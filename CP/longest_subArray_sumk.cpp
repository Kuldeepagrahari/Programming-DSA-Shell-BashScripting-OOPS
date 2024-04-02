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
        int n , k , x;
        cin >> n >> k ;
        int v[n];
        int sum = 0;
        for ( int i = 0; i < n ;i ++ ){ 
            cin >> v[i];
            sum += v[i];
        }
        int rest = sum - k;
        if ( sum < k )cout << "-1\n";
        else if ( sum == k )cout << "0\n";
        else 
        {   
           int pre [n+1] ;
           pre[0] = 0;
           for ( int i = 0; i <n ;i++ ){
            pre[i+1] = pre[i] + v[i];
           }
           int ans = 1e9;
            for ( int i = n; i >= 1 ;i -- ){
               int ind = lower_bound ( pre , pre + n +1 , pre[i] - k )-pre;
            //    cout << ind << " ";
               ans = min ( ans, ind-1+n+1-i );

            }
            cout << ans << endl;
        }
        } 
}