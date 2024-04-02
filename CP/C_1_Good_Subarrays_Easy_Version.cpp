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
        int n , k , x;
        cin >> n ;
        int v[n];
  
        for ( int i = 0; i < n ;i ++ ){ 
            cin >> v[i];
          
        }
        queue < int > q;
        int ans = 0;
        int preC = 0;
        for ( int i = 0; i< n; i++ ){
            int c = 0;
            if ( q.size() > v[i] - 1 ){
                c = q.size();
            while ( q.size() > v[i] - 1 ){
                q.pop();
            }
            q.push(v[i]);
            int cnt = c*(c+1)/2 - preC;
            ans += cnt;
            int s = q.size()-1;
            preC = s*(s+1)/2;

            }
            else q.push(v[i]);
            
            

        }
        int c = q.size();
        
        
        int cnt = c*(c+1)/2 - preC;
            ans += cnt;
        cout << ans  << endl;





        } 
}