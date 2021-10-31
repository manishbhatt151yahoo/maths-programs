#include<bits/stdc++.h>
using namespace std;

int countNums(int n, int x, int y)
{
	vector<bool> arr(n+1, false);

	if (x <= n)
		arr[x] = true;
	if (y <= n)
		arr[y] = true;
	int result = 0;

	for (int i=min(x, y); i<=n; i++)
	{
		if (arr[i])
    {		
			if (i+x <= n)
				arr[i+x] = true;
			if (i+y <= n)
				arr[i+y] = true;

			result++;
		}
	}
	return result;
}

int main()
{
	int n = 15, x = 5, y = 7;
	cout << countNums(n, x, y);
	return 0;
}
