#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Function to solve the Traveling Salesman Problem using dynamic programming
int tsp(const vector<vector<int>>& graph, int start, vector<vector<int>>& dp, int mask) {
    int n = graph.size();
    if (mask == (1 << n) - 1) // Base case: All cities visited
        return graph[start][0];

    // If this subproblem has already been solved, return the result
    if (dp[start][mask] != -1)
        return dp[start][mask];

    int ans = INF;
    for (int next = 0; next < n; ++next) {
        if ((mask & (1 << next)) == 0) { // If the next city is not visited yet
            int new_mask = mask | (1 << next);
            ans = min(ans, graph[start][next] + tsp(graph, next, dp, new_mask));
        }
    }

    // Memoize the result
    dp[start][mask] = ans;
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the distance between each pair of cities:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int minCost = tsp(graph, 0, dp, 1);
    cout << "Minimum cost of the tour: " << minCost << endl;

    return 0;
}


//O(n^2*2^n)  n is number of cities