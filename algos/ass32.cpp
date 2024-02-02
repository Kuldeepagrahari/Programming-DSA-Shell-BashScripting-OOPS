#include <bits/stdc++.h>
using namespace std;

int main()
{
  
//    --------- sort row wise ussing bubble sort--------
// int m;
// cout<<"enter m";
// cin>>m;
int arr[3][3]={{2,4,1},{4,5,9},{2,3,2}};

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        for(int k=j+1;k<3;k++){
            if(arr[i][j]>arr[i][k])swap(arr[i][j],arr[i][k]);
        }
    }
}

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}
