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
        int n ;
        // f, k ;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for ( int i = 0 ; i  <n ; i ++ ){
           cin >> a[i];
        }
        
        map <int, int > mp;

         for ( int i = 0 ; i  < n ; i ++ ){
           cin >> b[i];
           mp[b[i]] ++;
        }


        int m;
        cin >> m;

        vector<int> d(m);
        for ( int i = 0 ; i < m ; i ++ ){
           cin >> d[i];
        }

        int f = 0;

        for ( int i = 0 ; i < m ; i++ ){
            if ( i != m - 1 ){
               if ( mp[d[i]] > 0 ){
                   mp[d[i]]--;
               }
              
            }
            else{
                if ( mp[d[i]] == 0 ){
                    f = 1;
                    
                }
                else mp[d[i]]--;
            }
        }
       for ( int i = 0 ;i < n;  i++ ){
              if ( a[i] != b[i]  && mp[b[i]] > 0 ) f = 1;
       }
       if ( f  == 1 )cout << "NO\n";
       else cout << "YES\n";

 
 
   }
}