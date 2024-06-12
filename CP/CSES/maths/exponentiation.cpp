#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

// int exp ( int a, int b ){
   
//    if ( b == 0 )return 1;
//    int half = exp( a, b/2 ) % mod;

//    if ( b & 1 ) return ( a * half * half ) % mod;

//    else return (half * half) % mod;
// }
int power(int  x, long n)
{
    // int ans=x;
    if (n == 0)
    {
        return 1;
    }
 int half = power(x, n / 2);
    if (n % 2 == 0)
    {
        return (half * half) % mod;
    }

    return (x * half * half) % mod;
}
signed main () {
ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int t;
    cin >> t;

    while ( t-- ){
        int a, b;
        cin >> a >> b;
        cout << power(a % mod, b) << endl;
    }


}

