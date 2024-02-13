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
void arrayPrint ( int v[], int n ){
    for ( int i = 0;i < n; i++ ){
        cout << v[i] << " ";
    }
    cout << endl;
}
int countKdivPairs(int A[], int n, int K)
{
	
	int freq[K] = { 0 };

	
	for (int i = 0; i < n; i++)
		++freq[A[i] % K];

	
	int sum = freq[0] * (freq[0] - 1) / 2;


	for (int i = 1; i <= K / 2 && i != (K - i); i++)
		sum += freq[i] * freq[K - i];

	if (K % 2 == 0)
		sum += (freq[K / 2] * (freq[K / 2] - 1) / 2);
	return sum;
}
void same(){

}

signed main()
{
        int t;
        cin>>t;
        while(t--){
        int n,x,y;
        cin >> n >> x >> y;
        int v[n];
       
   
        for ( int i=0;i<n;i++){
           cin>>v[i];
       
        }

        int lcm = ( x * y)/__gcd(x,y);
         sort(v,v+n);
        int c=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(v[i]==v[i+1] && (v[i]+v[i+1])%x==0)c++;
            else{
                mx=max(c,mx);
                c=0;
            }
        }
        mx=max(c,mx);
        int ans = countKdivPairs(v,n,lcm);

        ans+=mx*(mx+1)/2;
        // if( mx != 0) ans++;
        cout<<mx<<" ";
        cout << ans <<endl;

       
     
       
       
      
           
}}