#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int a[n1],b[n2];
    int max1=0;
    for(int i=0;i<n1;i++) cin>>a[i];
    for(int i=0;i<n1;i++)
    {
        if(a[i]>max1) max1=a[i];
    }
    for(int i=0;i<n2;i++) cin>>b[i];
    int c[max1+1]={0};
    for(int i=0;i<n1;i++)
    {
        c[a[i]]++;
    }
    int r=0;
    int d[max1+1]={0};
    for(int i=0;i<n2;i++)
    {
        while(c[b[i]]!=0)
        {
            d[r]=b[i];
            r++;
            c[b[i]]--;
        }
    }
    for(int i=0;i<n1;i++) {if(d[i]==0)break;else cout<<d[i]<<" ";}
    for(int i=0;i<n1;i++) 
    {
        if(c[a[i]]!=0) cout<<a[i]<<" ";
    }
    cout<<endl;
}