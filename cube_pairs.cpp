#include <bits/stdc++.h>
using namespace std;

void findPairs(int n)
{
	int cubeRoot = pow(n, 1.0/3.0);

	unordered_map<int, pair<int, int> > s;

	for (int x = 1; x < cubeRoot; x++)
	{
		for (int y = x + 1; y <= cubeRoot; y++)
		{
			int sum = x*x*x + y*y*y;

			if (sum != n)
				continue;

			if (s.find(sum) != s.end())
			{
				cout << "(" << s[sum].first << ", "
					<< s[sum].second << ") and ("
					<< x << ", " << y << ")" << endl;
			}
			else
				s[sum] = make_pair(x, y);
		}
	}
}

int main()
{
	int n = 1383;
	findPairs(n);
	return 0;
}
