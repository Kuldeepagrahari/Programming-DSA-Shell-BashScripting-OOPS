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
        int n, k ;
        cin >> n  >> k;
        // vector<int> v(n);
        // vector<int> v2(n+1);
        // for ( int i = 0 ; i  <n ; i ++ ){
        //    cin >> v[i];
        // }
        //  for ( int i = 0 ; i  <n+1 ; i ++ ){
        //    cin >> v2[i];
        // }
        
        string s;
        cin >> s;
        map<char, int >mp;

        for ( int i = 0 ; i < n ; i ++  ){
            mp[s[i]]++;
        }

        int ans = 0;
        int size = mp.size();
        ans += k * (7 - size);

        for (auto it: mp  ){
             if ( it.second < k ){
                ans += k - it.second;
             }
        }

        cout << ans << endl;


       
    
 
 
   }
}