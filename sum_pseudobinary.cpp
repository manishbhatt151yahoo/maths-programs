#include<iostream>
using namespace std;

void psuedoBinary(int n)
{
	while (n > 0)
	{				
		int temp = n, m = 0, p = 1;
		while (temp)
		{
			int rem = temp % 10;
			temp = temp / 10;

			if (rem != 0)
				m += p;
			
			p *= 10;
		}
		
		cout << m << " ";

		n = n - m;
	}
}

int main()
{
	int n = 31;

	psuedoBinary(n);

	return 0;
}
