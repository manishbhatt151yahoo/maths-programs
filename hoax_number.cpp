#include <bits/stdc++.h>
using namespace std;
vector<int> primeFactors(int n)
{
	vector<int> res;
	if (n % 2 == 0) {
		while (n % 2 == 0)
			n = n / 2;
		res.push_back(2);
	}

	for (int i = 3; i <= sqrt(n); i = i + 2) {

		if (n % i == 0) {
			while (n % i == 0)
				n = n / i;
			res.push_back(i);
		}
	}

	if (n > 2)
		res.push_back(n);
	return res;
}

bool isHoax(int n)
{
	vector<int> pf = primeFactors(n);
	
	if (pf[0] == n)
		return false;
	
	int all_pf_sum = 0;
	for (int i = 0; i < pf.size(); i++) {

		int pf_sum;
		for (pf_sum = 0; pf[i] > 0;
			pf_sum += pf[i] % 10, pf[i] /= 10)
			;

		all_pf_sum += pf_sum;
	}

	int sum_n;
	for (sum_n = 0; n > 0; sum_n += n % 10,
								n /= 10)
		;

	return sum_n == all_pf_sum;
}

int main()
{
	int n = 84;
	if (isHoax(n))
		cout << "A Hoax Number\n";
	else
		cout << "Not a Hoax Number\n";
	return 0;
}
