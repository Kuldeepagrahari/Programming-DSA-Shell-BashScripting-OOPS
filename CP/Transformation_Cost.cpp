
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

int decToBinary(int n) 
{ 
    // array to store binary number 
    
  int binaryNum[32]; 
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    
  
} 
signed main()
{   
    int  t;
    cin>>t;

	while(t--){
        int n;
        cin>>n;
        int x=n;
 int binaryNum[32]={0}; 
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  

        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
    int ind=-1;
    reverse(binaryNum,binaryNum+32);
    // for(int i=0;i<32;i++)cout<<binaryNum[i]<<" ";
    int ind2=-1,ind3=-1;
    for(int i = 0; i< 32;i++){
        if(binaryNum[i]==1){
            ind2=i;break;
        }
    }
    for(int i=0;i<32;i++){
        if(binaryNum[i]==1){
            ind3=i;
        }
    }
    int f=0;
    for(int i=ind2;i<=ind3;i++){
        if(binaryNum[i]==0){f=1;break;}
    }
    for(int i=1;i<32;i++){
        if(binaryNum[i] ==0 && binaryNum[i-1]==1){
            ind = i;break;
        }
    }
    int val=0;
    

    for(int i=ind;i<32;i++){
        if(binaryNum[i]==1)
        val+=pow(2,31-i);
    }
    // cout<<val << " "<< ind<<" ";
    if(f==1){
    int ans= pow(2,31-ind)-val;
    
    cout<<ans<<endl;}
    else cout<<"0\n";

       
    }
}
