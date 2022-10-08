// C++ program to find minimum number of steps needed
// to convert a number x into y with two operations
// allowed : (1) multiplication with 2 (2) subtraction
// with 1.
#include <bits/stdc++.h>
using namespace std;

// A node of BFS traversal
struct node {
	int val;
	int level;
};

// Returns minimum number of operations
// needed to convert x into y using BFS
int minOperations(int x, int y)
{
	// To keep track of visited numbers
	// in BFS.
	set<int> visit;

	// Create a queue and enqueue x into it.
	queue<node> q;
	node n = { x, 0 };
	q.push(n);

	// Do BFS starting from x
	while (!q.empty()) {
		// Remove an item from queue
		node t = q.front();
		q.pop();

		// If the removed item is target
		// number y, return its level
		if (t.val == y)
			return t.level;

		// Mark dequeued number as visited
		visit.insert(t.val);

		// If we can reach y in one more step
		if (t.val * 2 == y || t.val - 1 == y)
			return t.level + 1;

		// Insert children of t if not visited
		// already
		if (visit.find(t.val * 2) == visit.end()) {
			n.val = t.val * 2;
			n.level = t.level + 1;
			q.push(n);
		}
		if (t.val - 1 >= 0
			&& visit.find(t.val - 1) == visit.end()) {
			n.val = t.val - 1;
			n.level = t.level + 1;
			q.push(n);
		}
	}
}

// Driver code
int main()
{
	int x = 4, y = 7;
	cout << minOperations(x, y);
	return 0;
}
