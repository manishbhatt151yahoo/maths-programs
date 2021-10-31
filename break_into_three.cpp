// C++ program to count number of ways to break
// a number in three parts.
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Function to count number of ways
// to make the given number n
ll count_of_ways(ll n)
{
	ll count = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= n; k++)
				if (i + j + k == n)
					count++;
	return count;
}

// Driver Function
int main()
{
	ll n = 3;
	cout << count_of_ways(n) << endl;
	return 0;
}
