#include<bits/stdc++.h>
using namespace std;

float findArea(float a)
{
	float area;

	area = (sqrt(5 * (5 + 2 * (sqrt(5)))) * a * a) / 4;

	return area;
}

int main()
{
	float a = 5;
	
	cout << "Area of Pentagon: " << findArea(a);
	
	return 0;
}
