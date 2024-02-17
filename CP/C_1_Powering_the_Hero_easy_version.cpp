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
          int n;
          cin >> n;
          int v[n];
          for ( int i =0 ;i < n ; i++){
            cin >> v[i];
          }

        //   int i = n-1, j = n-1;
          int ans = 0;
          priority_queue < int  > pq;
          for ( int i = 0 ; i < n ; i ++ ){
               if ( v[ i ] == 0 ){
                if ( !pq.empty() ){
                    // cout << i<<" ";
                   ans += pq.top();
                   pq.pop();
                }
                }
                else {
                    pq.push ( v[i] );
                }
               
            //    cout << pq.size()<<" ";
          }
          
          cout << ans <<endl;
       


       




    }

}


