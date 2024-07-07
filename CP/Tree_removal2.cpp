#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Node {
    int value;
    int index;
    
    bool operator<(const Node& other) const {
        return value <= other.value; 
    }
};

vector<int> maxScoreRemoval(vector<vector<int>>& edges, vector<int>& nodeValues) {
    int n = nodeValues.size();
    vector<unordered_set<int>> adj(n);
    vector<int> degree(n, 0);
    vector<int> result;

    // Building the graph
    for (const auto& edge : edges) {
        int u = edge[0] - 1, v = edge[1] - 1; // Convert to 0-based index
        adj[u].insert(v);
        adj[v].insert(u);
        degree[u]++;
        degree[v]++;
    }

    // Priority queue to keep track of nodes with odd degrees and their values
    priority_queue<Node> pq;
    for (int i = 0; i < n; ++i) {
        if (degree[i] % 2 != 0) {
            pq.push({nodeValues[i], i});
        }
    }

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int index = node.index;
        if (degree[index] % 2 == 0) continue;  // If degree is even, skip it

        // Add the node to the result
        result.push_back(index + 1); // Convert back to 1-based index

        // Remove the node from the graph
        for (int neighbor : adj[index]) {
            adj[neighbor].erase(index);
            if (degree[neighbor] % 2 != 0) {
                pq.push({nodeValues[neighbor], neighbor});
            }
            degree[neighbor]--;
        }
        adj[index].clear();
        degree[index] = 0;
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> nodeValues(N);
        for (int i = 0; i < N; ++i) {
            cin >> nodeValues[i];
        }

        vector<vector<int>> edges(N - 1, vector<int>(2));
        for (int i = 0; i < N - 1; ++i) {
            cin >> edges[i][0] >> edges[i][1];
        }

        vector<int> result = maxScoreRemoval(edges, nodeValues);
        
        cout << result.size() << endl;
        if (!result.empty()) {
            for (int i = 0; i < result.size(); ++i) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << endl;
        }
    }

    return 0;
}
