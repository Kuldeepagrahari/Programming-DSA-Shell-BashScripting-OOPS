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


signed main()
{
    int n;
    cin >> n;
    while ( n-- ){
        int c , m ,x;
        cin >> c >> m >> x;
   
        int ans = 0;
       
        int mini = min ( { c,m,x});
        c-=mini;
        m-=mini;
        x-=mini;
        ans+=mini;

        if ( x == 0 && m!=0 && c!=0){
            ans += ( m + c) / 3;
        }
        cout << min(ans , min ( cc , mm ))<< endl;
    }
}