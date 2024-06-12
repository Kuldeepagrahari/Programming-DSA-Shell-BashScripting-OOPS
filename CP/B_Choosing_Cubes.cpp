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


// ------------------------ lets begin sam --------------
signed main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
 
    while ( t-- ){

        // int x, y, a, b, c, d, m , n;
        int n, f, k ;
        cin >> n  >> f >>  k;
        vector<int> v(n);
        // vector<int> v2(n+1);
        for ( int i = 0 ; i  <n ; i ++ ){
           cin >> v[i];
        }
        //  for ( int i = 0 ; i  <n+1 ; i ++ ){
        //    cin >> v2[i];
        // }
        
        int fav = v[f-1];
        int f0 = 0, f1 = 0, f10 = 0;

        sort ( v.begin(), v.end() , greater<int>());

        for ( int i = 0 ; i <  n ; i++ ){
            if ( i < k ){
               if ( v[i] == fav )f1 = 1;
            }
            else if ( i >= k ){
                if ( v[i] == fav && f1 == 1 )f10  = 1;
                else if ( v[i] == fav )f0 = 1;
            }
        }

        if ( f10 == 1 )cout << "MAYBE\n";
        else if ( f1 == 1 )cout << "YES\n";
        else cout << "NO\n";

      

       
    
 
 
   }
}