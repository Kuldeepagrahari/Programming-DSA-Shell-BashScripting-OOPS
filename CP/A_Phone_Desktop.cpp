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
 
        cin >> x >> y;

        int ans = y%2==0 ? y / 2 : y / 2 + 1;
        int single_boxes = y%2!=0 ? 7 * ans + 4 : ans * 7;

        if ( x > single_boxes ){
            x -= single_boxes;
            ans += x%15==0 ? x/15 : x/15+1;
        }
        

        cout << ans << endl;


        // vector < int > v ( n );
        // printer(v);

    
 
 
   }
}