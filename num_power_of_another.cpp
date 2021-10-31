#include <bits/stdc++.h>
using namespace std;

bool isPower(int x, long int y)
{
	if (x == 1)
		return (y == 1);

	long int pow = 1;
	while (pow < y)
		pow *= x;
	return (pow == y);
}

int main()
{
	cout << isPower(10, 1) << endl;
	cout << isPower(1, 20) << endl;
	return 0;
}
