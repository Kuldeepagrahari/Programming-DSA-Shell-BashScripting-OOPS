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
          cin >> k >> n;
          vector<int > ans;
          int elem = 1;
          int i = 0;
          int size = 1;
          while ( n-elem >= k-size && size <= k){
            ans.push_back(elem );
            size++;
            elem += ++i;
          }
          int last = ans[ans.size()-1];
          size = ans.size();
          for ( int i = 0; i < k-size; i++)ans.push_back(++last);
          
          printer(ans);


        
          
    }

}


