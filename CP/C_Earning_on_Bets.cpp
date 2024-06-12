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

int getRightMostSetBit(int n)
{
    if (n == 0)
        return 0;
 
    return log2(n & -n) + 1;
}
 

int posOfRightMostDiffBit(int m, int n)
{
    return getRightMostSetBit(m ^ n);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
// Returns LCM of array elements
int findlcm(vector<int>&arr, int n)
{
    // Initialize result
    int ans = arr[0];
 
    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
 
    return ans;
}
// ------------------------ lets begin sam --------------
signed main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
 
    while ( t-- ){

        int x, y, a, b, c, d, m , n;
 
        cin >> n ;
        vector < int > v ( n );
        for ( int i = 0 ; i < n ; i++ ){
           cin >> v[i];
        }  
        // sort ( v.begin(), v.end());
       
        // int gcdd = 1;
        // for ( int i = 0; i< n ; i++ ){
        //     gcdd =  __gcd(gcdd, v[i]);
        // }
        int lcmm = findlcm(v,n);
        vector<int> ans;
        for ( int i = 0 ; i < n ; i++ ){
            ans.push_back(lcmm/v[i]);
        }
        int sum = 0;
        for ( auto x:ans ){
 sum += x;
        }
int f = 0;
        for ( int i = 0; i< n; i++){
            if ( v[i]*ans[i] <= sum){
                f = 1;
                break;
            }
        }

        if ( f == 1 )cout << "-1\n";
        else 



         
        printer(ans);

    
 
 
   }
}