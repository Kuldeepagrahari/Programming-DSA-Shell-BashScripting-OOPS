
#include<bits/stdc++.h>

using namespace std;
#define int long long

int xorPairCount(int arr[], int n, long long x)
{
	int result = 0; 
	unordered_map<int, int> m;

	for (int i=0; i<n ; i++)
	{
		int curr_xor = x^arr[i];

		if (m.find(curr_xor) != m.end() ){
			result += m[curr_xor];
            // m.erase(curr_xor);
        }

		 m[arr[i]]++;
	}



	return result;
}


signed main()
{   
    int  t;
    cin>>t;

	while(t--){
        int n;
        cin>>n;
        int v[n];
        for ( int i = 0; i< n ;i ++ ){
            cin>>v[i];
        }
        sort(v,v+n);
        int cnt = count(v,v+n,2147483647);
        int cnt0 = count(v,v+n,0);
        int inip = min(cnt,cnt0);
        long long k =2147483647;
        cout<<min(n/2,xorPairCount(v,n,k))<<endl;
    }
}
