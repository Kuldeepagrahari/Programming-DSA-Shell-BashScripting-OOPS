#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename Container>
void printer(const Container &container)
{

    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
// --------------------------------------------------
template <typename Container>
void pairprint(const Container &container)
{

    for (auto it = std::begin(container); it != std::end(container); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

int LO(vector<int> &nums, int target, int l, int r)
{

    int lo = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            lo = mid;
            l = mid + 1;
        }
        else if (nums[mid] > target)
        {

            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return lo;
}
int FO(vector<int> &nums, int target, int l, int r)
{

    int fo = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            fo = mid;
            r = mid - 1;
        }
        else if (nums[mid] > target)
        {

            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return fo;
}

// ------------------------ lets begin sam --------------
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {

        int x, y, a, b, c, d, m, n ,k;

        cin >> n ;
        // vector<pair<int, int>> vp;
        vector<int> v(n);
        vector<int> maxi(n);
        vector<int> pre(n+1,0);
        // vector<int> v2(n);

        for ( int i = 0 ; i < n ; i ++ )cin >> v[i];
        // for ( int i = 0 ; i < n ; i ++ )cin >> v2[i];
     
        for ( int i = 0 ; i< n; i++ ){
            pre[i+1] = pre[i] + v[i];
        }
        maxi[0] = v[0];
        for ( int i = 1 ; i < n ; i++ ){
            maxi[i] = max ( maxi[i-1],v[i] ) ;
            // cout << "maxi:" << maxi[i] << " ";
        }
        int sam = 0;
        for ( int i = 0 ;i < n ; i++ ){
            int rest = pre[i+1] - maxi[i];
            if ( rest == maxi[i]){
                sam++;
            }
        }

        // printer(maxi);
        // printer(pre);
        // cout << "-------------------------";
        cout << sam << endl;

          
       
     


       

        // printer(v);
        // pairprint(v);
    }
}