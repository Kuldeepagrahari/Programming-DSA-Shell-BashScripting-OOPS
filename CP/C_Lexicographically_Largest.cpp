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
          cin >> n;
          int v[n];
           set<int>st;
          for ( int i = 0; i< n ;i++ ){
            cin >> v[i];
            v[i] += ( i+1 );
            
          }

          sort ( v, v+n , greater<int>());
        // reverse ( v,v+n );
       
        vector<int>ans;
        for ( int i = 0 ;i < n ;i ++ ){
            if ( st.count(v[i]) == 0 ){
                st.insert(v[i]);
                
            }
            else {
                v[i] = v [i-1] -1;
                st.insert(v[i]);
            }
        }
        for ( int i = 0;i < n ;i ++ ){
            if ( v[i] > 0 )ans.push_back(v[i]);
        }
        printer(ans);
        




        
          
    }

}


