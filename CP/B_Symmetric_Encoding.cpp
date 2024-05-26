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

        int x, y, a, b, c, d, m , n;
 
        cin >> n;

        string ss;
        cin >> ss;

        set<char> st;

        for ( int i = 0 ; i < n ; i ++ ){
            st.insert( ss[i] );

        }

        string s = "";
        for ( auto it : st ){
             s += it;
        }

        map<char,char> mp;
        int ls = s.length();
        for (int i = 0 ; i <  ls ; i ++ ){
           mp[s[i]] = s[ls-i-1];
        }

        for ( int i = 0 ; i < n; i ++  ){
            ss[i] = mp[ss[i]];
        }




        cout << ss << endl;


       

        // vector < int > v ( n );
        // printer(v);

    
 
 
   }
}