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

int linear(int a[],int n,int ind,int k)
{
    if (ind>=n){
        return -1;
    }
    if(a[ind]!=k)linear(a,n,ind+1,k);
    else return ind;
}
int main()
{
    //    in(a);
    int n, k;
    cout << "enter n:";
    cin >> n;
    userInput(a, n);
    print(a, n);
    cout << "enter num to search:";
    cin >> k;
    // iterative linear search
    // tc:o(n)
    // sc: o(1) no extra space req
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

    // recursive 
    // sc:o(n) worst and avg case
    // tc:o(n) avg case
    int ans=linear(a,n,0,k);
    if(ans==-1)cout<<"not found\n";
    else cout<<"found at "<<ans<<endl;    
}
