#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
int findMinDiff(int a, int b, int x, int y)
{
	int g = gcd(a,b);

	int diff = abs(x-y) % g;

	return min(diff, g - diff);
}

int main()
{
	int a = 20, b = 52, x = 5, y = 7;

	cout << findMinDiff(a, b, x, y) << endl;

	return 0;
}
