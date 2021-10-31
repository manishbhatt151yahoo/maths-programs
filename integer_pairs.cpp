#include <iostream>
using namespace std;

// This function counts number of pairs (x, y) that satisfy
// the inequality x*x + y*y < n.
int countSolutions(int n)
{
int res = 0;
for (int x = 0; x*x < n; x++)
	for (int y = 0; x*x + y*y < n; y++)
		res++;
return res;
}

// Driver program to test above function
int main()
{
	cout << "Total Number of distinct Non-Negative pairs is "
		<< countSolutions(6) << endl;
	return 0;
}
