#include <bits/stdc++.h>
using namespace std;
vector<int> v2;

#include <bits/stdc++.h>
bool sam(int n, int k, int ind, vector<int> &arr, vector<vector<int>> &dp)
{
    if (k == 0)
        return true;
    if (ind == 0)
        return (arr[0] == k);

    if (dp[ind][k] != -1)
        return dp[ind][k];//return from memory
    // take
    bool take = false;
    if (arr[ind] <= k)
    {
        // k -= arr[ind];
        take = sam(n, k - arr[ind], ind - 1, arr, dp);
    }

    // not take
    bool notTake = sam(n, k, ind - 1, arr, dp);
    //    that (index,target) will be banned only if it return false on taking and notTaking
    //    both cond not only just one otherwise it should not be banned and hence used 'OR'
    return dp[ind][k] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    if (sam(n, k, n - 1, arr, dp))
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (subsetSumToK(n, k, arr))
        cout << "yes";
    else
        cout << "no";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
}