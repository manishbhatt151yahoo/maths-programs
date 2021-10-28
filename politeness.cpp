#include <iostream>
using namespace std;

int countOddPrimeFactors(int n)
{
	int result = 1;

	while (n % 2 == 0)
		n /= 2;

	for (int i = 3; i * i <= n; i += 2) {
		int divCount = 0;

		while (n % i == 0) {
			n /= i;
			++divCount;
		}

		result *= divCount + 1;
	}

	if (n > 2)
		result *= 2;

	return result;
}

int politness(int n)
{
	return countOddPrimeFactors(n) - 1;
}

int main()
{
	int n = 90;
	cout << "Politness of " << n << " = "
		<< politness(n) << "\n";

	n = 15;
	cout << "Politness of " << n << " = "
		<< politness(n) << "\n";
	return 0;
}
