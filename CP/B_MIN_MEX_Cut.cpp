#include <bits/stdc++.h>
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
    cin>>t;
    while(t--){
        // int n;
        // cin >> n;
        string s;
        cin >> s;
        int n = s.length();
        int cnt =0;
        int c0 = count ( s.begin(),s.end(),'0');
        int c1 = count ( s.begin(),s.end(),
    '1');
    int c01 = count ( s.begin(),s.end(),
    "01");
    int c10 = count ( s.begin(),s.end(),
    "10");
        
       if ( c0 == 0 )cout << "0\n";
       else if ( c1 == 0 )cout << "1\n";
       else if ( c0 == 1 )cout << "1\n";
       else {
        if ( c01 >= 1 && c10)
       }



       
      

       ;
         
        
    }
}