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
          int pro = 1; 
          vector <int> ans;
          for ( int i = 2; i * i <= n ;i++ ){
             if (n % i == 0 ){
               if( ans.size() < 2 ){
                pro *= i;
                ans.push_back(i);
               }
              else break;
              }
          }

          if ( ans.size() == 2  ){
            
            if ( n/pro != ans[0] && n/pro != ans[1]){
                ans.push_back(n/pro);
            cout << "YES\n";
            printer(ans);
            }
            else cout<<"NO\n";
          }

          else cout<<"NO\n";
          
    }

}


