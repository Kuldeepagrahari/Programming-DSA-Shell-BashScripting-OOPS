#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
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
signed main()
{      
       int t;
       cin >> t;
       while ( t-- ){
          int n , k;
         string s;
        cin>>n;
        vector<int>v;
        set<int>st;
        for(int i=0;i<n;i++){
            cin>>s;
            v.push_back(count(s.begin(),s.end(),'1'));
            if(count(s.begin(),s.end(),'1') > 0)
            st.insert(count(s.begin(),s.end(),'1'));
        }
        if(st.size()==1)cout<<"SQUARE\n";
        else cout<<"TRIANGLE\n";



        
          
    }

}


