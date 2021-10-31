#include <bits/stdc++.h>
using namespace std;

double compute(int a, int b)
{

	double AM, GM, HM;

	AM = (a + b) / 2;
	GM = sqrt(a * b);
	HM = (GM * GM) / AM;
	return HM;
}
int main()
{

	int a = 5, b = 15;
	double HM = compute(a, b);
	cout << "Harmonic Mean between " << a
		<< " and " << b << " is " << HM ;
	return 0;
}
