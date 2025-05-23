// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum
// cost path for all the paths
void findMinRoute(vector<vector<int> > tsp)
{
	int sum = 0;
	int counter = 0;
	int j = 0, i = 0;
	int min = INT_MAX;
	map<int, int> visitedRouteList;

	// Starting from the 0th indexed
	// city i.e., the first city
	visitedRouteList[0] = 1;
	int route[tsp.size()];

	// Traverse the adjacency
	// matrix tsp[][]
	while (i < tsp.size() && j < tsp[i].size())
	{

		// Corner of the Matrix
		if (counter >= tsp[i].size() - 1)
		{
			break;
		}

		// If this path is unvisited then
		// and if the cost is less then
		// update the cost
		if (j != i && (visitedRouteList[j] == 0))
		{
			if (tsp[i][j] < min)
			{
				min = tsp[i][j];
				route[counter] = j + 1;
			}
		}
		j++;

		// Check all paths from the
		// ith indexed city
		if (j == tsp[i].size())
		{
			sum += min;
			min = INT_MAX;
			visitedRouteList[route[counter] - 1] = 1;
			j = 0;
			i = route[counter] - 1;
			counter++;
		}
	}

	// Update the ending city in array
	// from city which was last visited
	i = route[counter - 1] - 1;

	for (j = 0; j < tsp.size(); j++)
	{

		if ((i != j) && tsp[i][j] < min) 
		{
			min = tsp[i][j];
			route[counter] = j + 1;
		}
	}
	sum += min;

	// Started from the node where
	// we finished as well.
	cout << ("Minimum Cost is : ");
	cout << (sum);
}

// Driver Code
int main()
{

	// Input Matrix
	vector<vector<int> > tsp = { { -1, 10, 15, 20 },
								{ 10, -1, 35, 25 },
								{ 15, 35, -1, 30 },
								{ 20, 25, 30, -1 } };

	// Function Call
	findMinRoute(tsp);
}


