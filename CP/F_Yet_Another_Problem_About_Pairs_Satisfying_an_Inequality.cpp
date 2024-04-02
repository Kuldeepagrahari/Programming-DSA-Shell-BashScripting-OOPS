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
        cin >> n ;
        int v[n];
  
        for ( int i = 0; i < n ;i ++ ){ 
            cin >> v[i];
          
        }
        
        vector < int > vec ;
        vector<int> ind;
        for ( int i= 0; i< n ;i++ ){
            if ( v[ i ] < (i+1) ){
                vec.push_back( v[i] );
                ind.push_back( i+1 );
            }
        }
        sort ( vec.begin(),vec.end());
        int ans = 0;
        for ( int i= 0; i< ind.size(); i++ ){
            int index = lower_bound(vec.begin(),vec.end(),ind[i] + 1 ) - vec.begin();

            ans += ( ind.size() - index );
        }
        cout << ans << endl;  






        } 
}