#include <bits/stdc++.h>
using namespace std;

long long derivativeTerm(string pTerm, long long val)
{
	string coeffStr = "";
	int i;
	for (i = 0; pTerm[i] != 'x'; i++)
		coeffStr.push_back(pTerm[i]);
	long long coeff = atol(coeffStr.c_str());
	string powStr = "";
	for (i = i + 2; i != pTerm.size(); i++)
		powStr.push_back(pTerm[i]);
	long long power = atol(powStr.c_str());

	return coeff * power * pow(val, power - 1);
}

long long derivativeVal(string& poly, int val)
{
	long long ans = 0;

	istringstream is(poly);

	string pTerm;
	while (is >> pTerm) {
		if (pTerm == "+")
			continue;
	
		else
			ans = (ans + derivativeTerm(pTerm, val));
	}
	return ans;
}

int main()
{
	string str = "4x^3 + 3x^1 + 2x^2";
	int val = 2;
	cout << derivativeVal(str, val);
	return 0;
}
