#include <bits/stdc++.h>
using namespace std;

string integer_to_string(int n, int base)
{
	string str;
	while (n > 0) {
		int digit = n % base;
		n /= base;
		str.push_back(digit + '0');
	}
	return str;
}

int isPalindrome(int i, int k)
{
	int temp = i;
	
	int m = 0;
	while (temp > 0) {
		m = temp % 10 + m * 10;
		temp /= 10;
	}
	if (m == i) {
	
		string str = integer_to_string(m, k);
		string str1 = str;
		reverse(str.begin(), str.end());
	
		if (str == str1) {
			return i;
		}
	}
	return 0;
}

void sumPalindrome(int n, int k){
	
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += isPalindrome(i, k);
	}
	cout << "Total sum is " << sum;
}

int main()
{
	int n = 100;
	int k = 2;

	sumPalindrome(n, k);
	return 0;
}
