#include<bits/stdc++.h>
#define PI 3.14
using namespace std;

float areaOfInscribedCircle(float a)
{
	return ( PI / 4 ) * a * a;
}

int main()
{
	float a = 8;
	
	cout << "Area of an inscribed circle: "
		<< areaOfInscribedCircle(a);
		
	return 0;
}
