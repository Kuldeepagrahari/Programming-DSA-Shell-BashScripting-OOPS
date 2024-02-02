#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {3, 5, 3, 7, 8, 7, 2};
    int ar[9]={-3,-3,-2,-7,4,9,6,7,4};
    int maxi = *max_element(arr, arr + 7);
    vector<int> v(maxi + 1, 0);

    for (int i = 0; i < 7; i++)
    {
        v[arr[i]]++;
    }
    int j = 0;

    for (int i = 0; i <= maxi; i++)
    {
        if (v[i] != 0)
        {
            while (v[i] != 0)
            {
                arr[j++] = i;
                v[i]--;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}