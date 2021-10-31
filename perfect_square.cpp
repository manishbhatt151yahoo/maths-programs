#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int n)
{
	for (int sum = 0, i = 1; sum < n; i += 2) {
		sum += i;
		if (sum == n)
			return true;
	}
	return false;
}

int main()
{
	isPerfectSquare(35) ? cout << "Yes\n" : cout << "No\n";
	isPerfectSquare(49) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
