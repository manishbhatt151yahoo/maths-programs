// C++ program to count number of pair of positions
// in matrix which are not accessible
#include<bits/stdc++.h>
using namespace std;

// Counts number of vertices connected in a component
// containing x. Stores the count in k.
void dfs(vector<int> graph[], bool visited[],
							int x, int *k)
{
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (!visited[graph[x][i]])
		{
			// Incrementing the number of node in
			// a connected component.
			(*k)++;

			visited[graph[x][i]] = true;
			dfs(graph, visited, graph[x][i], k);
		}
	}
}

// Return the number of count of non-accessible cells.
int countNonAccessible(vector<int> graph[], int N)
{
	bool visited[N*N + N];
	memset(visited, false, sizeof(visited));

	int ans = 0;
	for (int i = 1; i <= N*N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;

			// Initialize count of connected
			// vertices found by DFS starting
			// from i.
			int k = 1;
			dfs(graph, visited, i, &k);

			// Update result
			ans += k * (N*N - k);
		}
	}
	return ans;
}

// Inserting the edge between edge.
void insertpath(vector<int> graph[], int N, int x1,
							int y1, int x2, int y2)
{
	// Mapping the cell coordinate into node number.
	int a = (x1 - 1) * N + y1;
	int b = (x2 - 1) * N + y2;

	// Inserting the edge.
	graph[a].push_back(b);
	graph[b].push_back(a);
}

// Driven Program
int main()
{
	int N = 2;

	vector<int> graph[N*N + 1];

	insertpath(graph, N, 1, 1, 1, 2);
	insertpath(graph, N, 1, 2, 2, 2);

	cout << countNonAccessible(graph, N) << endl;
	return 0;
}
