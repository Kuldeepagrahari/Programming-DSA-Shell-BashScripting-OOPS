#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> v(n);
        vector<int> v2(m);

        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < m; i++)
            cin >> v2[i];

        if (m == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] > v2[0])
                    v[i] = v2[0];
            }
        }
        else
        {

            int mini = *min_element(v2.begin(), v2.end());

            while (v2[0] != mini)
            {
                rotate(v2.begin(), v2.begin() + 1, v2.end());
            }
         
            int f = -1;
            int ind = -1;

            for (int i = 0; i < n - m + 1; i++)
            {
                if (v[i] < v2[0])
                    continue;
                else if (v[i] == v2[0])
                {
                    continue;
                }
                else
                {
                    f = 1;
                    ind = i;
                    break;
                }
            }
            int k = 0;
            if ( ind == -1 )
            for (int j = n - m; j < n; j++)
            {
                if (v[j] < v2[k])
                    break;
                if (v2[k] < v[j])
                {
                    f = 1;
                    ind = n - m;
                    break;
                }
                k++;
            }
            if (ind != -1)
            {
                for (int i = ind; i < n - m + 1; i++)
                    v[i] = mini;
                int k = 0;
                for (int i = n - m; i < n; i++)
                    v[i] = v2[k++];
            }
        }
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
}