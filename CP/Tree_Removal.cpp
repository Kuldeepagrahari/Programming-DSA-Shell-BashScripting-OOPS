#include <bits/stdc++.h>
using namespace std;

#define fl(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vi A(n + 1);
        fl(i, 1, n + 1) cin >> A[i];
        vii adj(n + 1);
        vi degree(n + 1, 0);

        fl(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            degree[u]++;
            degree[v]++;
        }

        priority_queue<pair<int, int>> pq;

        for (int i = 1; i <= n; i++)
        {
            if (degree[i] % 2 != 0)
            {
                pq.push({A[i], i});
            }
        }

        vi result;
        int maxScore = 0;

        while (!pq.empty())
        {
           int  score = pq.top().first;
           int  vertex = pq.top().second;
            pq.pop();

            if (degree[vertex] % 2 == 0)
            {
                continue;
            }

            maxScore += score;
            result.pb(vertex);

            for (int neighbor : adj[vertex])
            {
                degree[neighbor]--;
                if (degree[neighbor] % 2 != 0)
                {
                    pq.push({A[neighbor], neighbor});
                }
            }

            degree[vertex] = 0;
        }

        cout << result.size() << endl;
        for (int x : result)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
