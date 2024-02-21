// <IntPairPair, vector<IntPairPair>, greater<IntPairPair>>: This part specifies the template arguments for the
//  priority queue:

// IntPairPair: This is the type of elements that the priority queue will hold. In this case, it's a pair 
// consisting of an integer
//  (int) as the first element and another pair of integers as the second element.
// vector<IntPairPair>: This is the underlying container used by the priority queue. Here, it's a vector of 
// IntPairPair. Priority 
// queue internally uses this vector to store elements.
// greater<IntPairPair>: This is a comparator function or functor that defines the priority order. It specifies 
// how elements are 
// compared to determine their priority. In this case, greater is used, which means the elements are sorted in
//  non-ascending order, making it behave as a min priority queue. greater is a standard 
// comparator that compares elements using the > operator. It's provided by the C++ Standard Library.

#include <bits/stdc++.h>
using namespace std;

class MST
{
public:
	
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};


int main() {

	int V = 5;
    // {u,v,w}
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	MST obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}