// C++ program to find maximum product of two
// non-intersecting paths
#include <bits/stdc++.h>
using namespace std;

/* Returns maximum length path in subtree rooted
	at u after removing edge connecting u and v */
int dfs(vector<int> g[], int& curMax, int u, int v)
{
	// To find lengths of first and second maximum
	// in subtrees. currMax is to store overall
	// maximum.
	int max1 = 0, max2 = 0, total = 0;

	// loop through all neighbors of u
	for (int i = 0; i < g[u].size(); i++)
	{
		// if neighbor is v, then skip it
		if (g[u][i] == v)
			continue;

		// call recursively with current neighbor as root
		total = max(total, dfs(g, curMax, g[u][i], u));

		// get max from one side and update
		if (curMax > max1)
		{
			max2 = max1;
			max1 = curMax;
		}
		else
			max2 = max(max2, curMax);
	}

	// store total length by adding max
	// and second max
	total = max(total, max1 + max2);

	// update current max by adding 1, i.e.
	// current node is included
	curMax = max1 + 1;
	return total;
}

// method returns maximum product of length of
// two non-intersecting paths
int maxProductOfTwoPaths(vector<int> g[], int N)
{
	int res = INT_MIN;
	int path1, path2;

	// one by one removing all edges and calling
	// dfs on both subtrees
	for (int i = 1; i < N+2; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			// calling dfs on subtree rooted at
			// g[i][j], excluding edge from g[i][j]
			// to i.
			int curMax = 0;
			path1 = dfs(g, curMax, g[i][j], i);

			// calling dfs on subtree rooted at
			// i, edge from i to g[i][j]
			curMax = 0;
			path2 = dfs(g, curMax, i, g[i][j]);

			res = max(res, path1 * path2);
		}
	}
	return res;
}

// Utility function to add an undirected edge (u,v)
void addEdge(vector<int> g[], int u, int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}

// Driver code to test above methods
int main()
{
	int edges[][2] = {{1, 8}, {2, 6}, {3, 1},
					{5, 3}, {7, 8}, {8, 4},
					{8, 6} };
	int N = sizeof(edges)/sizeof(edges[0]);

	// there are N edges, so +1 for nodes and +1
	// for 1-based indexing
	vector<int> g[N + 2];
	for (int i = 0; i < N; i++)
		addEdge(g, edges[i][0], edges[i][1]);

	cout << maxProductOfTwoPaths(g, N) << endl;
	return 0;
}
