#include <iostream> 
using namespace std; 
class gfg { 

public: 
	float squareRoot(float n) 
	{
		float x = n; 
		float y = 1; 
		float e = 0.000001;
		while (x - y > e) { 
			x = (x + y) / 2; 
			y = n / x; 
		} 
		return x; 
	} 
}; 

int main() 
{ 
	gfg g; 
	int n = 50; 
	cout << "Square root: " << "is " << g.squareRoot(n); 
	getchar(); 
} 
