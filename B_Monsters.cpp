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

class comp{
public:
    bool operator()(pair<int,int> p1, pair<int,int> p2 ){
       if (p1.first != p2.first)
            return p1.first < p2.first; 
       return p1.second > p2.second; 
    }
};

signed main(){
        
        int t;
        cin >> t;
        while ( t-- ){
        int n , k , m;
        cin >> n >> k;
        int v[n];
        for ( int i = 0; i < n ; i++ )cin >> v[i];

        priority_queue< pair <int,int>, vector<pair<int,int>>, comp > pq;

        for ( int i = 0; i < n ; i ++ ){
           if ( v[i]%k == 0 )
           pq.push({k,i+1});
           else  pq.push({v[i]% k,i+1 });
        }
        

        while ( !pq.empty()){
            auto it = pq.top();
            int val = it.first;
            int ind = it.second;
            pq.pop();
           cout << ind << " ";
        }
        cout << endl;
        
       
        




        } 
}