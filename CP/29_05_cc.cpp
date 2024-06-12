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
        vector<int> alt;
    int c = 0;
    alt.push_back(0);
        for ( int i = n-2 ; i >= 0 ; i-- ){
            if ( s[i] != s[i+1] ){
                c++;
                alt.push_back(c);
                if ( i!=0)
                alt.push_back(c);
                i--;
                
            }
            else {
                alt.push_back(c);
            }

        }
        reverse(alt.begin(), alt.end());
        int m = n;
        int ans = 0;
        for ( int i = 0 ; i  < n ;i ++ ){
            ans += alt[i]*2+ (m-alt[i])*1;
            m--;
        }

        // printer(alt);
        cout << ans << endl;
        for ( int i = 0; i< n ; i++ ){
            
        }



       

         
        // printer(v);

    
 
 
   }
}