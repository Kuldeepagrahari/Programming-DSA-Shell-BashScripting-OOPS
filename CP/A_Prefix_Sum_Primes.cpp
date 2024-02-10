#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int v[n];
    int c=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==1)c++;
    }
    int cnt_2=n-c;
    if(cnt_2>0)cout<<"2 ";
    if(c>0)cout<<"1 ";
    if(cnt_2-1>0)
    for(int i=0;i<cnt_2-1;i++)cout<<"2 ";
    if(c-1>0)for(int i=0;i<c-1;i++)cout<<"1 ";

    
    // for(int i=0;i<n;i++)cout<<v[i]<<" ";
    // cout<<endl;
}
