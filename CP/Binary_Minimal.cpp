#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
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
signed main(){
        
        int t;
        cin >> t;
        while ( t-- ){
        int n , k , m;
        string s;
        cin >> n >> k;
         cin >> s;
        string s1 = s;
        int c1=count(s.begin(),s.end(),'1');
        if ( c1 == 0 ){
            for ( int i = 0; i< k ;i++ )s.erase(s.begin());
        }

        else {
            int x=min(c1,k);
            int z=x;
           for ( int i =0 ;i< n;i++){
            if ( x<=0)break;
            if ( s[i] == '1'){
                s.erase(s.begin()+i);
            x--;
            }
            
           }

           int y =k-z;
           for ( int i = 0; i < y; i++)s.erase(s.begin());
        
         
         int w=z;
         int v=w;
         for ( int i = 0; i< n ; i++ ){
            if ( w <=0)break;
            if ( s1[i] == '1'){
                s1[i] = '0';
                w--;
            }
         }

         int g=k-v;
         for ( int i = 0; i< n; i++ ){
            if ( )
         }
        }
         cout << s << endl;




        } 
}