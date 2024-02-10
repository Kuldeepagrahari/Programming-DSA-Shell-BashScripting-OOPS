#include <bits/stdc++.h>
using namespace std;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define mii map<int, int>
#define msi map<string, int>
#define umap unordered_map
#define pb push_back
#define ppb pop_back
#define fl(i, a, b) for (int i = a; i < b; i++)
 
#define int long long
 
 
const int M = 1e9 + 7;
template <typename Container>
void printer(const Container& container) {
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
// --------------------------------------------------
template <typename Container>
void pairprint(const Container& container) {
    // Use iterator to loop through the container
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}
/*--------------------------------------functions---------------------------------------------------------------------*/
int binmultiply(int a, int b)
{
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}
// -------------------------------------------divide & conquer---------------
   double power(double x, long n){
        // int ans=x;
         if (n == 0) {
            return 1.0;
        }
        double half = power(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } 
 
            return x * half * half;
        
    }
/*---------------------------------------------*/
 
/*---------------------------------------------------*/
int fact(int n)
{
 
    int ans = 1;
    fl(i, 1, n + 1)
    {
        ans = (ans * i)%M;
    }
    return ans;
}
 
// ----------------------------------------------------
 
/*---------------------------------------------------*/
const int N = 1e18;
/*---------------------------------------------------*/
const double epsilon = 1e-6;
 
double squareroot(int n)
{
    double mid, l = 1, r = n;
    while (r - l >= epsilon)
    {
        mid = l + (r - l) / 2;
        if (mid * mid == n)
            return mid;
        else if (mid * mid < n)
        {
            l = mid;
        }
        else
            r = mid;
    }
    return mid;
}
 
// /*---------------------------------------------------*/
const long long X = 1e12;
int isprime(long long n)
{ // sieve algo
    vi v(X, 1);
    v[0] = v[1] = 0;
    fl(i, 2, X)
    {
        if (v[i] == 1)
        {
            for (int j = 2 * i; j < X; j += i)
            {
                v[j] = 0;
            }
        }
    }
    if (v[n])
        return 1;
    else
        return 0;
}
 
 unordered_map<int,int> primes(long long n)
{ // sieve algo
    vi v(n, 1);
    v[0] = v[1] = 0;
     unordered_map<int,int> primefac;
    fl(i, 2, n)
    {
        if (v[i] == 1)
        {   primefac[i]=1;
            for (int j = 2 * i; j < n; j += i)
            {
                v[j] = 0;
            }
        }
        else primefac[i*i]=0;
    }
   
  
 return primefac;
}
// /*---------------------------------------------------*/
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
// /*---------------------------------------------------*/
 
/*---------------------------------------------------*/
const int ARR = 1e7;
void primefactors(int n)
{
    vi v(ARR, 1);
    vi lp(ARR, 0), hp(ARR, 0);
    v[0] = v[1] = 0;
    fl(i, 2, ARR)
    {
        if (v[i] == 1)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < ARR; j += i)
            {
                v[j] = 0;
                hp[j] = i;
                if (lp[j] == 0)
                    lp[j] = i;
            }
        }
    }
    vi pfs; // to count no of occu of any part. factor use unordered map
    while (n > 1)
    {
        int pf = hp[n];
        while (n % pf == 0)
        {
            n /= pf;
            pfs.pb(pf);
        }
    }
    fl(i, 0, pfs.size()) cout << pfs[i] << " ";
    cout << endl;
}
 
 
const int MAX_CHAR = 256;
int strtoint(string a, int n)
{ // array element to integer
    int x = 0;
    fl(i, 0, n)
    {
        if (a[i] != ':')
        {
            x += ((int)a[i] - 48);
            x *= 10;
        }
    }
    return (x / 10);
}
// -----------------------------------------------------
 
int bin(vi v,int a,int n){
    int ans=0;
    fl(i,0,n){
       ans+=abs(v[i]-a);
    }
    return ans;
}
// --------------------------------------------
// ---------------------------------------------------------------------------------------------
/*ssssssssssssssssssssssssssssssssssssssssssssssssssssssss   jai mata di  ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss*/
// long double data type can be used to avoid precision (i.e. long double is more precise than double) during calculation of big nubers
// use 1ll with multiplication (x*1ll*y where x,y are very large numbers)to avoid overflow
// ans*=k%M -->(wrong)
// ans=(ans*k)%M -->(right to avoid overflow)
// (n&(n-1))==0 cond for num to be pow of 2
// SWAP: A=A^B;B=B^A;A=A^B;
// function calling bhi kafi time leta h to constraint
// jada badi ho to function calling avoid karo
// =============================================================================================================
// ****************************************************************************************************************
                    // -l-----------------------------------------------l
//  ******************l square root sqrtl(n) use kr long long ke liye l************************************8888
                    //   l ----------------------------------------------l
// =======================================================================================================
// ****************************************************************************************************************
    // all_of(ar, ar+6, [](int x) { return x>0; })?
    //       cout << "All are positive elements" :
    //       cout << "All are not positive elements";
    // --------------------------------------------------
    
    // any_of(ar, ar+6, [](int x){ return x<0; })?
    //       cout << "There exists a negative element" :
    //       cout << "All are positive elements";
     // partitioning vector using partition()
    //  ----------------------------------------------------------
    // partition(vect.begin(), vect.end(), [](int x)
    // {
    //     return x%2==0;
         
    // });
     
//     vector<int> vect = { 2, 1, 5, 6, 8, 7 };
// The partitioned vector is : 2 8 6 5 1 7,  
// -----------------------------------------------------------
// // MEMSET
//    char str[] = "geeksforgeeks"; 
//     memset(str, 't', sizeof(str)); 
//     cout << str;
// Output
// tttttttttttttt
/*---------------------------------------------- Lets' begin -------------------------------------------------------*/
 bool isPerfectSquare(long double x)
{  
  
    if (x >= 0) {
    //    if x is long long then  sqrtl(x)
        long long sr = sqrt(x);
         
     
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
#define MOD 1000000007
 
// Extended Euclidean algorithm
int xGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
 
    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (long long)(a / b) * y1;
    return gcd;
}
 
// factorial of n modulo MOD
int modfact(int n) {
    int result = 1;
    while (n > 1) {
        result = (long long)result * n % MOD;
        n -= 1;
    }
    return result;
}
 
// multiply a and b modulo MOD
int modmult(int a, int b) {
    return (long long)a * b % MOD;
}
 
// inverse of a modulo MOD
int inverse(int a) {
    int x, y;
    xGCD(a, MOD, x, y);
    return x;
}
 
// binomial coefficient nCk modulo MOD
int bc(int n, int k)
{    if(n==k)return 1;
    return modmult(modmult(modfact(n), inverse(modfact(k))), inverse(modfact(n - k)));
}
//  -------------------------------------------------------------------------
signed main()
{
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin>>n;
        vi v(n);
        fl(i,0,n)cin>>v[i];
        sort(all(v));
        mii mp;
        int cnt=1;
        printer(v);
        fl(i,0,n-1){
            if(v[i]==v[i+1])cnt++;
            else{
                mp[i-cnt+1]=cnt;
                cnt=1;
                
            }
        }
        mp[n-cnt]=cnt;
        pairprint(mp);
        int ans=0;
        // cout<<bc(2,2);
        for(auto&sam:mp){
            
            if(sam.second>=2){
                int nC2=1LL*(sam.second)*(sam.second-1)/2;
                int nC3=1LL*(sam.second)*(sam.second-1)*(sam.second-2)/6;
                ans+=nC2*sam.first;
                // cout<<ans<<endl;
                if(sam.second>=3)ans+=nC3;
            }
        }
    // cout<<bc(3000,3)<<endl;
 
    cout<<ans<<endl;
    }
 
}
/*----------------------------------------------THE END-----------------------------------------------------------------*/
int lenint(int n)
{ // length of integer
    return floor(log10(n) + 1);
}
/*---------------------------------------------------*/
 
 
template <typename T>
void remove(std::vector<T> &v, const T &target) // to remove all occurence of target element in vector
{                                               // call: remove(v,target);
    v.erase(std::remove(all(v), target), v.end());
}