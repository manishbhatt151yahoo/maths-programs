#include <bits/stdc++.h>
using namespace std;

int compute_average(int a, int b)
{
	return (a + b) / 2;
}

// Driver code
int main()
{
	int a = INT_MAX, b = INT_MAX;

	cout << "Actual average : " << INT_MAX << endl;

	cout << "Computed average : " << compute_average(a, b);

	return 0;
}
