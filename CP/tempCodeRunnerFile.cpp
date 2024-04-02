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
        int n , k , m,a,b,l;
        cin >> a >> b >> l;
        int pa = 1, pb = 1 ;
        vector<int > posa;
        vector<int> posb;
        while ( pa <= l ) {
           if ( l % pa == 0 )posa.push_back(pa);
           pa *= a;

        }
        while ( pb <= l ) {
           if ( l % pb == 0 )posb.push_back(pb);
           pb *= b;

        }
        // printer(posa);
        // printer(posb);
        int na = 0;
        unordered_set<int > st;
        for ( int i = 0; i < posa.size(); i++ ){
            for ( int j = 0; j < posb.size(); j++ ){
                if ( posa[i]*posb[j] > l ) na++;
                else st.insert(l/(posa[i]*posb[j]));
            } 
        }
        // int ans = posa.size()*posb.size()-na;
        cout << st.size() << endl;

       
       
        




        } 
}