// C++ program to minimize subtree sum
// difference by one edge deletion
#include <bits/stdc++.h>
using namespace std;

/* DFS method to traverse through edges,
calculating subtree sum at each node and
updating the difference between subtrees */
void dfs(int u, int parent, int totalSum,
		vector<int> edge[], int subtree[], int& res)
{
	int sum = subtree[u];

	/* loop for all neighbors except parent and
		aggregate sum over all subtrees */
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != parent)
		{
			dfs(v, u, totalSum, edge, subtree, res);
			sum += subtree[v];
		}
	}

	// store sum in current node's subtree index
	subtree[u] = sum;

	/* at one side subtree sum is 'sum' and other side
		subtree sum is 'totalSum - sum' so their difference
		will be totalSum - 2*sum, by which we'll update
		res */
	if (u != 0 && abs(totalSum - 2*sum) < res)
		res = abs(totalSum - 2*sum);
}

// Method returns minimum subtree sum difference
int getMinSubtreeSumDifference(int vertex[],
					int edges[][2], int N)
{
	int totalSum = 0;
	int subtree[N];

	// Calculating total sum of tree and initializing
	// subtree sum's by vertex values
	for (int i = 0; i < N; i++)
	{
		subtree[i] = vertex[i];
		totalSum += vertex[i];
	}

	// filling edge data structure
	vector<int> edge[N];
	for (int i = 0; i < N - 1; i++)
	{
		edge[edges[i][0]].push_back(edges[i][1]);
		edge[edges[i][1]].push_back(edges[i][0]);
	}

	int res = INT_MAX;

	// calling DFS method at node 0, with parent as -1
	dfs(0, -1, totalSum, edge, subtree, res);
	return res;
}

// Driver code to test above methods
int main()
{
	int vertex[] = {4, 2, 1, 6, 3, 5, 2};
	int edges[][2] = {{0, 1}, {0, 2}, {0, 3},
					{2, 4}, {2, 5}, {3, 6}};
	int N = sizeof(vertex) / sizeof(vertex[0]);

	cout << getMinSubtreeSumDifference(vertex, edges, N);
	return 0;
}
