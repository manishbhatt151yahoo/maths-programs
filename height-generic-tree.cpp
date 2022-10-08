// C++ code to find height of N-ary
// tree in O(n)
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

// Adjacency list to
// store N-ary tree
vector<int> adj[MAX];

// Build tree in tree in O(n)
int build_tree(int arr[], int n)
{
	int root_index = 0;

	// Iterate for all nodes
	for (int i = 0; i < n; i++) {

		// if root node, store index
		if (arr[i] == -1)
			root_index = i;

		else {
			adj[i].push_back(arr[i]);
			adj[arr[i]].push_back(i);
		}
	}
	return root_index;
}

// Applying BFS
int BFS(int start)
{
	// map is used as visited array
	map<int, int> vis;

	queue<pair<int, int> > q;
	int max_level_reached = 0;

	// height of root node is zero
	q.push({ start, 0 });

	// p.first denotes node in adjacency list
	// p.second denotes level of p.first
	pair<int, int> p;

	while (!q.empty()) {

		p = q.front();
		vis[p.first] = 1;

		// store the maximum level reached
		max_level_reached = max(max_level_reached,
								p.second);

		q.pop();

		for (int i = 0; i < adj[p.first].size(); i++)

			// adding 1 to previous level
			// stored on node p.first
			// which is parent of node adj[p.first][i]
			// if adj[p.first][i] is not visited
			if (!vis[adj[p.first][i]])
				q.push({ adj[p.first][i], p.second + 1 });
	}

	return max_level_reached;
}

// Driver Function
int main()
{
	// node 0 to node n-1
	int parent[] = { -1, 0, 1, 2, 3 };

	// Number of nodes in tree
	int n = sizeof(parent) / sizeof(parent[0]);

	int root_index = build_tree(parent, n);

	int ma = BFS(root_index);
	cout << "Height of N-ary Tree=" << ma;
	return 0;
}
