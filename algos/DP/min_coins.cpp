#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cns[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cns[i];
    }
    sort(cns, cns + n, greater<int>());
    cout << " enter amount";
    int k;
    cin >> k;
    int i = 0;
    int ans = 0;

     clock_t start, end;
 

    start = clock();

    while (i < n)
    {
        if (cns[i] <= k)
        {
            k -= cns[i];
            ans++;
        }
        else
        {
            i++;
        }
    }
    if (k != 0)
        cout << "-1\n";
    else
        cout << ans << endl;

        // t.c: o(nlogn)
         end = clock();
 

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;


}


