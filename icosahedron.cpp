#include <bits/stdc++.h>
using namespace std;

float findArea(float a)
{
	float area;

	area = 5 * sqrt(3) * a * a;
	
	return area;
}

float findVolume(float a)
{
	float volume;

	volume = ((float)5 / 12) * (3 + sqrt(5)) * a * a * a;
	
	return volume;
}

int main()
{
	float a = 5;
	cout << "Area: " << findArea(a) << endl;
	
	cout << "Volume: " << findVolume(a);

	return 0;
}
