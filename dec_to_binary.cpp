// C++ implementation of decimal to binary conversion
// without using arithmetic operators
#include <bits/stdc++.h>

using namespace std;

// function for decimal to binary conversion
// without using arithmetic operators
string decToBin(int n)
{
	if (n == 0)
		return "0";
	
	// to store the binary equivalent of decimal
	string bin = "";
	while (n > 0)
	{
		// to get the last binary digit of the number 'n'
		// and accumulate it at the beginning of 'bin'
		bin = ((n & 1) == 0 ? '0' : '1') + bin;
		
		// right shift 'n' by 1
		n >>= 1;
	}
	
	// required binary number
	return bin;
}

// Driver program to test above
int main()
{
	int n = 38;
	cout << decToBin(n);
	return 0;
}
