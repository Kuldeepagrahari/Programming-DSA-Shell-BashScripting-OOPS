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
        int n;
        cin >> n ;
        string s;
        cin >> s;
        int f = 1;
        for ( auto c: s){
            if (! ( ( c >= 'a' && c <= 'z' ) || ( c >= '0' && c <= '9'))) f = 0;
        }

        if ( f ){
            string ss = s;
            sort ( s.begin(), s.end() );
            if ( s == ss )cout << "YES\n";
            else cout << "NO\n";

        }
        else{
            cout << "NO\n";
        }
    
 
 
   }
}