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


// ------------------------
signed main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
 
    while ( t-- ){

       int n , m ; 
       cin  >> n  >> m;
       if ( m > n )cout << "No\n";

       else {
        if ( n&1){
            if ( m&1)cout << "YES\n";
            else cout << "No\n";
        }
        else {
             if ( m&1)cout << "NO\n";
            else cout << "YES\n";
        }
       }
      

       
    }
}
            