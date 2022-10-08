// C++ program to find minimum initial
// vertices to reach whole matrix.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// (n, m) is current source cell from which
// we need to do DFS. N and M are total no.
// of rows and columns.
void dfs(int n, int m, bool visit[][MAX],
		int adj[][MAX], int N, int M)
{
	// Marking the vertex as visited
	visit[n][m] = 1;

	// If below neighbor is valid and has
	// value less than or equal to current
	// cell's value
	if (n + 1 < N &&
		adj[n][m] >= adj[n + 1][m] &&
		!visit[n + 1][m])
		dfs(n + 1, m, visit, adj, N, M);

	// If right neighbor is valid and has
	// value less than or equal to current
	// cell's value
	if (m + 1 < M &&
		adj[n][m] >= adj[n][m + 1] &&
		!visit[n][m + 1])
		dfs(n, m + 1, visit, adj, N, M);

	// If above neighbor is valid and has
	// value less than or equal to current
	// cell's value
	if (n - 1 >= 0 &&
		adj[n][m] >= adj[n - 1][m] &&
		!visit[n - 1][m])
		dfs(n - 1, m, visit, adj, N, M);

	// If left neighbor is valid and has
	// value less than or equal to current
	// cell's value
	if (m - 1 >= 0 &&
		adj[n][m] >= adj[n][m - 1] &&
		!visit[n][m - 1])
		dfs(n, m - 1, visit, adj, N, M);
}

void printMinSources(int adj[][MAX], int N, int M)
{
	// Storing the cell value and cell indices
	// in a vector.
	vector<pair<long int, pair<int, int> > > x;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			x.push_back(make_pair(adj[i][j],
						make_pair(i, j)));


	// Sorting the newly created array according
	// to cell values
	sort(x.begin(), x.end());

	// Create a visited array for DFS and
	// initialize it as false.
	bool visit[N][MAX];
	memset(visit, false, sizeof(visit));

	// Applying dfs for each vertex with
	// highest value
	for (int i = x.size()-1; i >=0 ; i--)
	{
		// If the given vertex is not visited
		// then include it in the set
		if (!visit[x[i].second.first][x[i].second.second])
		{
			cout << x[i].second.first << " "
				<< x[i].second.second << endl;
			dfs(x[i].second.first, x[i].second.second,
			visit, adj, N, M);
		}
	}
}

// Driver code
int main()
{
	int N = 2, M = 2;

	int adj[N][MAX] = {{3, 3},
					{1, 1}};
	printMinSources(adj, N, M);
	return 0;
}
