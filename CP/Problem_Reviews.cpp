
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
        int f=1;
        int v[n];
         for(int i=0;i<n;i++)cin>>v[i];
         for(int i=0;i<n;i++){
            if(v[i]<=4){
                f=0;break;
            }
         }
         if(f==1)cout<<"YES\n";
         else cout<<"NO\n";
    }
}
