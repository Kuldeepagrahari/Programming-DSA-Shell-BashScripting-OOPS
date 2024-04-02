#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    vector<vector<int>> graph = {
        {INF, 5, 3, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 2, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 6, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, 7, 8, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, 9, 4, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 2, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 1, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}
    };
    vector<int> cost(13, INF);
    cost[1] = 0;
    for (int i = 2; i <= 12; ++i) {
        for (int u = 1; u < i; ++u) {
            if (graph[u - 1][i - 1] != INF && cost[u] != INF && cost[u] + graph[u - 1][i - 1] < cost[i]) {
                cost[i] = cost[u] + graph[u - 1][i - 1];
            }
        }
    }
    cout << "Minimum cost of traveling from town 1 to town 12: " << cost[12] << endl;


}