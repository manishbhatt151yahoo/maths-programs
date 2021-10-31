#include <iostream>
#include <cmath>
using namespace std;

float InverseSquareRoot(float x)
{
	return 1/sqrt(x);
}

int main()
{
	cout << InverseSquareRoot(0.5) << endl;
	cout << InverseSquareRoot(3.6) << endl;
	cout << InverseSquareRoot(1.0) << endl;
	return 0;
}
