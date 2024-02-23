
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
        int r,w;
        int v[22];
        for(int i=0;i<22;i++){
            cin>>r>>w;
            v[i] = r+20*w;
        }
        int maxi=0,ind;
        for (int i=0;i<22;i++){
            if(v[i]>maxi){
                maxi=v[i];
                ind=i;
            }
        }
        cout<<ind+1<<endl;
       
    }
}
