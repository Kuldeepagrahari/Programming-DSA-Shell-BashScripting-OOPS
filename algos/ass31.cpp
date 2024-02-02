#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
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
// -------------- t(n)=1+t(n/2)--------------
int binary_search(int a[],int n,int k)
{    
    int mid;
    int l=0,r=n-1;
    int ind=-1;
    while(r>=l){
        mid=l+(r-l)/2;
        if(a[mid]==k)ind=mid;
        else if(a[mid]<k){
            l=mid+1;
        }
        else r=mid-1;
    }
    
    return mid;
    
}
// ------- 0(n)--------------------------
bool linear(int a[],int k,int n){
      int flag = -1, ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            flag = 1;
            ind = i;
            break;
        }
    }
    if (flag == 1)
        cout << k << " found at index : " << ind << endl;
    else
        cout << "not found";
}

int main()
{
    //    in(a);
    int n, k;
    cout << "enter n:";
    cin >> n;
    cout<< "enter k to search";
    cin>>k;
    userInput(a, n);
    print(a, n);
    if(binary_search(a,n,k)==-1)cout<<"not found\n";
    else cout<<"found at : "<<" "<<binary_search(a,n,k);
    // ------ 2(b)----------------
    linear(a,k,n);
    
}