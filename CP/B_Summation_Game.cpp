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
    cin >> t;
    while(t--){
        int n , k , x;
        cin >> n >> k >> x;
        int v[n];
        for ( int i = 0; i < n; i++  ){
            cin >> v[i];
        }
        sort ( v, v +n );
        int sumk = 0;
        int sumRest = 0;
        int ck = 0;
        for ( int i = n-k-1; i >= n-k-x; i -- ){
            if ( i < 0 )break;
           sumk += v[i];
           ck ++;
        }

        for ( int i = n-k-x-1; i>= 0; i-- )sumRest += v[i];
        // cout << sumk << " " << sumRest << endl;
        priority_queue < int,vector<int > , greater<int> >pq;
        for ( int i = n-k ;i< n ;i ++ ){
              pq.push(v[i]);
        }
        int ans = sumRest-sumk;
        
        int j;
        if ( n-k-x >= 0 ) j =n - k -x;
        else j = 0;
        for ( int i =0; i< k ;i ++ ){
            int top = pq.top ();
            pq.pop();
            if ( ck < x ){
               sumk += top;
               ck++;
            }
             else if ( ck == x ){
                sumk += top;
                sumk -= v[j];
                sumRest += v[j];
                j++;
             }
             
            ans = max ( ans, sumRest - sumk );
        }
    

        cout << ans  << endl;

        
    }
}