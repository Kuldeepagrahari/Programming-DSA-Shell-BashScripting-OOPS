#include <bits/stdc++.h>
using namespace std;


int main()
{
    int arr[11] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr3[11];
    for(int i=0;i<11;i++)arr3[i]=arr[i];
    int arr2[6]={2,1,4,3,9,6};
   int maxi=0;
    for(int i=0;i<11;i++){
        if(arr[i]>maxi)maxi=arr[i];
    }
//   cout<<maxi;
    int v[maxi+1];
    for(int i=0;i<maxi+1;i++){
        v[i]=0;
    }

    for (int i = 0; i < 11; i++)
    {
        v[arr[i]]++;
    }
    
    int j = 0,k=0;
    int rest[11];
    for(int i=0;i<11;i++)rest[i]=-1;
    
    for(int i=0;i<6;i++){
        if(v[arr2[i]]!=0){
            arr3[arr2[i]]=-1;
        while(v[arr2[i]]--){
            arr[j++]=arr2[i];
        }}
       
    }
   for(int i=0;i<11;i++){
    if( arr3[i]!=-1){
        rest[k++]=i;
    }
   } 
    for(int i=0;i<11;i++){
        cout<<rest[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<11;i++){
        if(arr3[rest[i]]!=-1)
        arr[j++]=arr3[rest[i]];
    }
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
cout<<endl;
   
}