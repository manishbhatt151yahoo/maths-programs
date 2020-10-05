#include<bits/stdc++.h> 
using namespace std; 

int multiply(int x, int y) 
{ 
	if(y) 
		return (x + multiply(x, y - 1)); 
	else
		return 0; 
} 

int pow(int a, int b) 
{ 
	if(b) 
		return multiply(a, pow(a, b - 1)); 
	else
		return 1; 
} 

int main() 
{ 
	cout << pow(5, 3); 
	getchar(); 
	return 0; 
}
