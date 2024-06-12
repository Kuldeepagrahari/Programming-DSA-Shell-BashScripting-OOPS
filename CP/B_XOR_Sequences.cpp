#include<bits/stdc++.h>
using namespace std;
#define int long long
 
template <typename Container>
void printer(const Container &container)
{
    
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// --------------------------------------------------
template <typename Container>
void pairprint(const Container &container)
{
    
    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

int getRightMostSetBit(int n)
{
    if (n == 0)
        return 0;
 
    return log2(n & -n) + 1;
}
 

int posOfRightMostDiffBit(int m, int n)
{
    return getRightMostSetBit(m ^ n);
}
// ------------------------ lets begin sam --------------
signed main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
 
    while ( t-- ){

        int x, y, a, b, c, d, m , n;
 
        cin >> n >> m;
        // vector < int > v ( n );
        // for ( int i = 0 ; i < n ; i++ ){
        //    cin >> v[i];
        // }  
        // sort ( v.begin(), v.end());
        int ans = pow(2,posOfRightMostDiffBit(n,m) - 1);
        cout << ans << endl;
        
         
        // printer(v);

    
 
 
   }
}