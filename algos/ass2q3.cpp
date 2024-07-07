#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N];
void in(int a[])
{
    for (int i = 0; i < N; i++)
        a[i] = rand();
}
void userInput(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
// p is starting , q is mid, r is ending
void merge(int a[],int p,int q,int r){
    int n=q-p+2,m=r-q+1;
    int L[n];
    int R[m];
    L[n-1]=1e9;
    R[m-1]=1e9;
    int j=0;
    for(int i=p;i<=q;i++){
        L[j++]=a[i];
    }
    j=0;
    for(int i=q+1;i<=r;i++){
        R[j++]=a[i];
    }
    j=0;
    int i=p,k=q+1;
    while(j<=r-p){
        if(L[i]<=R[k])a[j++]=L[i++];
        else a[j++]=R[k++];
    }
// print(L,3);
}
void mergeSort(int a[],int p,int r){
    if(p<r){
        int mid=p+(r-p)/2;
        mergeSort(a,p,mid);
        mergeSort(a,mid+1,r);
        merge(a,p,mid,r);
    }
}
int main()
{
    //    in(a);
    int n, k;
    cout << "enter n:";
    cin >> n;
    userInput(a, n);
    print(a, n);
    // int arr[3]={7,2,3};
   
    // int p,l,h,mid;
    // for( p=2; p<=n; p*=2){
    //     for(int i=0;i+p-1<n;i+=p){
    //          l=i;
    //          h=i+p-1;
    //          mid=l+(h-l)/2;
    //         merge(a,l,mid,h);

    //     }
    // }
    // if(p/2<n)merge(a,0,p/2,n-1);
    // print(a,n);
    merge(a,0,n/2,n-1);
    print(a,n);
     
}
