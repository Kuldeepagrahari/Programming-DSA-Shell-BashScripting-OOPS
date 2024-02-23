
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
        // int n;
       int n,m,x,y,l;
       cin >> n >> m >> x >> y >> l;
       int x1=(n-x)/l;
       int x2=(x-1)/l;
       int y1=(m-y)/l;
       int y2=(y-1)/l;
       int ans=(x1+1+x2)*(y1+1+y2);
       cout<<ans<<endl;
       
    }
}
