#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n" 
#define no cout << "NO\n"  
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

// ---------------------------------------------------------
int ans ( int v[] , int n ,int k ){
     int ret = 0;
     for ( int i = 0; i< n ;i ++ ){
        ret += abs(v[i] - k);
     }
     return ret;
}
void arrayPrint ( int v[], int n ){
    for ( int i = 0;i < n; i++ ){
        cout << v[i] << " ";
    }
    cout << endl;
}

signed main()
{
       int n;
       cin >> n;
       int v[n];
       int med = 0;
       for ( int i =0 ;i < n ;i ++ ){cin >> v[i]; }
       int local_min = INT_MAX;
       int ans = 1;
       for ( int i = 0 ; i < n ; i++ ){
        if ( v[i] < local_min && i+1 != v[i] ){
            local_min = v[i];
            ans ++;
        }
       }
       cout << ans << endl;
          
       
   
       






        
}