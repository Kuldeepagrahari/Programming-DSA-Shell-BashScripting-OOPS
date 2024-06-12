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
        vector<int> v(n);
        vector<int> v2(n+1);
        for ( int i = 0 ; i  <n ; i ++ ){
           cin >> v[i];
        }
         for ( int i = 0 ; i  <n+1 ; i ++ ){
           cin >> v2[i];
        }

        int ans = 1;
        int mini = INT_MAX;
        int maxi = 0;
        int last = v2[n];

        for ( int i = 0 ; i < n ; i++ ){
            ans += abs ( v[i] - v2[i] );

            if (last <= max(v2[i], v[i])  && last >= min(v2[i],v[i])){
                continue;
            }
            else{
             mini = min ( abs( v[i]-last ), mini );
              mini = min ( abs( v2[i]- last), mini );
            }


        }
        if ( last <= maxi && last >= mini ){
            cout << ans << endl;
        }
        else {
            ans += min(abs(mini-last), abs(maxi-last));
            cout << ans << endl;
        }
    
 
 
   }
}