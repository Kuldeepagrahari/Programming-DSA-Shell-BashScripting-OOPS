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
           cin>>n;
          int v[2*n];
         
          for(int i=0;i<2*n;i++){
            cin>>v[i];
          }
          sort(v,v+2*n);
          int ans=0;
          for(int i =0; i< 2*n ; i+=2){
            ans+=v[i];
          }
          cout<<ans<<endl;
     



        
          
    }

}


