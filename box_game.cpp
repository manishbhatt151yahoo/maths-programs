#include <bits/stdc++.h>
using namespace std;

int minimumBox(int arr[], int n)
{
	queue<int> q;

	sort(arr, arr + n);

	q.push(arr[0]);

	for (int i = 1; i < n; i++) {

		int now = q.front();

		if (arr[i] >= 2 * now)
			q.pop();

		q.push(arr[i]);
	}

	return q.size();
}

int main()
{
	int arr[] = { 4, 1, 2, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minimumBox(arr, n) << endl;
	return 0;
}
