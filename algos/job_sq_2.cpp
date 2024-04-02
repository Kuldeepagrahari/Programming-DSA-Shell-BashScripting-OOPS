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

bool cmp(vector<int>v1, vector<int>v2 ){
        return v1[1] < v2[1];
    }
     
signed main(){
    // {id,dead,profit}
   vector<vector<int>>vp={{1,2,100},{2,1,19},{3,2,1},{4,1,25},{5,1,15}};
   sort(vp.begin(),vp.end(),cmp);
   priority_queue< vector<int> , vector< vector<int> >, greater<vector<int>> >pq;
   int curr = 1 ;
   for ( int i = 0; i < 5; i++ ){
    if ( vp[i][1] >= curr ){
        pq.push({vp[i][2], vp[i][1],vp[i][0]});
        curr++;
    }
    else{
        if ( vp[i][2] > pq.top()[0] ){
            pq.pop();
            pq.push({vp[i][2],vp[i][1],vp[i][0]});
        }
    }
   }
   int ans = 0;
   vector<int> seq;
   while ( !pq.empty()){
    ans += pq.top()[0];
    seq.push_back(pq.top()[2]);
    pq.pop();
   }
   reverse(seq.begin(),seq.end());
   for ( auto & ss : seq) cout << ss << "--> " ;
   cout << "end\n";
   cout << " maximum profit = " << ans << endl;
}