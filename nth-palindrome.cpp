// A naive approach of C++ program of finding nth
// palindrome of k digit
#include<bits/stdc++.h>
using namespace std;

// Utility function to reverse the number n
int reverseNum(int n)
{
	int rem, rev=0;
	while (n)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n /= 10;
	}
	return rev;
}

// Boolean Function to check for palindromic
// number
bool isPalindrom(int num)
{
	return num == reverseNum(num);
}

// Function for finding nth palindrome of k digits
int nthPalindrome(int n,int k)
{
	// Get the smallest k digit number
	int num = (int)pow(10, k-1);

	while (true)
	{
		// check the number is palindrom or not
		if (isPalindrom(num))
			--n;

		// if n'th palindrome found break the loop
		if (!n)
			break;

		// Increment number for checking next palindrome
		++num;
	}

	return num;
}

// Driver code
int main()
{
	int n = 6, k = 5;
	printf("%dth palindrome of %d digit = %d\n",
		n, k, nthPalindrome(n, k));

	n = 10, k = 6;
	printf("%dth palindrome of %d digit = %d",
		n, k, nthPalindrome(n, k));
	return 0;
}
