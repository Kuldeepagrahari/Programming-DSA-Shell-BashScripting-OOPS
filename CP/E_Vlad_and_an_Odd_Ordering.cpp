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
         string s;
        cin>>n>>k;
        int j = 1;
        int maxi = log(n)/log(2) +1;
int ans;
        while (maxi -- ){
            int y= pow(2,j);
            int y2=pow(2,j-1);
            int x =  (int)(n+y-y2)/y;
            if ( k > x){
                 k-=x;
                
                 
                  j++;
            }
            else {
                  ans = pow(2,j-1) + (k-1)*pow(2,j);
                  break;
            }
            // cout<<n<<" "<<k<<" ";
        }
        cout<<ans<<endl;




        
          
    }

}


