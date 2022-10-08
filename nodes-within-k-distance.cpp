// C++ program to count nodes inside K distance
// range from marked nodes
#include <bits/stdc++.h>
using namespace std;

// Utility bfs method to fill distance vector and returns
// most distant marked node from node u
int bfsWithDistance(vector<int> g[], bool mark[], int u,
										vector<int>& dis)
{
	int lastMarked;
	queue<int> q;

	// push node u in queue and initialize its distance as 0
	q.push(u);
	dis[u] = 0;

	// loop until all nodes are processed
	while (!q.empty())
	{
		u = q.front();	 q.pop();
		// if node is marked, update lastMarked variable
		if (mark[u])
			lastMarked = u;

		// loop over all neighbors of u and update their
		// distance before pushing in queue
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			
			// if not given value already
			if (dis[v] == -1)
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	// return last updated marked value
	return lastMarked;
}

// method returns count of nodes which are in K-distance
// range from marked nodes
int nodesKDistanceFromMarked(int edges[][2], int V,
							int marked[], int N, int K)
{
	// vertices in a tree are one more than number of edges
	V = V + 1;
	vector<int> g[V];

	// fill vector for graph
	int u, v;
	for (int i = 0; i < (V - 1); i++)
	{
		u = edges[i][0];
		v = edges[i][1];

		g[u].push_back(v);
		g[v].push_back(u);
	}

	// fill boolean array mark from marked array
	bool mark[V] = {false};
	for (int i = 0; i < N; i++)
		mark[marked[i]] = true;

	// vectors to store distances
	vector<int> tmp(V, -1), dl(V, -1), dr(V, -1);

	// first bfs(from any random node) to get one
	// distant marked node
	u = bfsWithDistance(g, mark, 0, tmp);

	/* second bfs to get other distant marked node
		and also dl is filled with distances from first
		chosen marked node */
	v = bfsWithDistance(g, mark, u, dl);

	// third bfs to fill dr by distances from second
	// chosen marked node
	bfsWithDistance(g, mark, v, dr);

	int res = 0;
	// loop over all nodes
	for (int i = 0; i < V; i++)
	{
		// increase res by 1, if current node has distance
		// less than K from both extreme nodes
		if (dl[i] <= K && dr[i] <= K)
			res++;
	}
	return res;
}

// Driver code to test above methods
int main()
{
	int edges[][2] =
	{
		{1, 0}, {0, 3}, {0, 8}, {2, 3},
		{3, 5}, {3, 6}, {3, 7}, {4, 5},
		{5, 9}
	};
	int V = sizeof(edges) / sizeof(edges[0]);
	
	int marked[] = {1, 2, 4};
	int N = sizeof(marked) / sizeof(marked[0]);

	int K = 3;
	cout << nodesKDistanceFromMarked(edges, V, marked, N, K);
	return 0;
}
