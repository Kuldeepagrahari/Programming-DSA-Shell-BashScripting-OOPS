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
   vector<pair<int,int>>vp={{2,100},{1,19},{2,27},{1,25},{1,15}};
   sort(vp.begin(),vp.end());
   priority_queue<int , vector<int>, greater<int> >pq;
   int curr = 1 ;
   for ( int i = 0; i < 5; i++ ){
    if ( vp[i].first >= curr ){
        pq.push(vp[i].second);
        curr++;
    }
    else{
        if ( vp[i].second > pq.top() ){
            pq.pop();
            pq.push(vp[i].second);
        }
    }
   }
   int ans = 0;
   while ( !pq.empty()){
    ans += pq.top();
    pq.pop();
   }

   cout << " maximum profit = " << ans << endl;
}