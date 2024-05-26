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


// ------------------------
signed main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
 
    while ( t-- ){

        int n;
 
        cin >> n;
        vector < int > v1 ( n );
        vector < int > v2 ( n );
        vector < int > v3 ( n );

        for (int i = 0 ; i  < n ; i ++ )cin >> v1[i];
        for (int i = 0 ; i  < n ; i ++ )cin >> v2[i];
        for (int i = 0 ; i  < n ; i ++ )cin >> v3[i];


       vector<pair<int,int>> vp1;
        vector<pair<int,int>> vp2;
         vector<pair<int,int>> vp3;

          for (int i = 0 ; i  < n ; i ++ )vp1.push_back({v1[i],i});
        for (int i = 0 ; i  < n ; i ++ )vp2.push_back({v2[i],i});
        for (int i = 0 ; i  < n ; i ++ )vp3.push_back({v3[i],i});

        // sort(vp1.begin(),vp1.end());
        //  sort(vp2.begin(),vp2.end());
        //   sort(vp3.begin(),vp3.end());
        
        //  reverse(vp1.begin(),vp1.end());
        //  reverse(vp2.begin(),vp2.end());
        //   reverse(vp3.begin(),vp3.end());

// ********* sorting vector of pair in reverse order************
             sort(vp1.rbegin(), vp1.rend());
        sort(vp2.rbegin(), vp2.rend());
        sort(vp3.rbegin(), vp3.rend());

        //   pairprint(vp1);
        //   pairprint(vp2);
        //   pairprint(vp3);
          vector < int > v4 ( 3 );
        vector < int > v5 ( 3 );
        vector < int > v6 ( 3 );

        v4[0] = vp1[0].second;
        v4[1] = vp1[1].second;
        v4[2] = vp1[2].second;
        v5[0] = vp2[0].second;
        v5[1] = vp2[1].second;
        v5[2] = vp2[2].second;
        v6[0] = vp3[0].second;
        v6[1] = vp3[1].second;
        v6[2] = vp3[2].second;

        int ans = 0;
        for ( auto it:v4 ){
           for ( auto it2: v5 ){
            for ( auto it3: v6 ){
                if ( it != it2 && it2 != it3 && it != it3){
                   ans = max ( ans, v1[it] + v2[it2] + v3[it3] );

                }}}}}}
            