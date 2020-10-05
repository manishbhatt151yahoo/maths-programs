#include <bits/stdc++.h> 
using namespace std; 
#define bool int 

bool isLucky(int n) 
{ 
	static int counter = 2; 
  
	int next_position = n; 
	if(counter > n) return 1; 
	if(n % counter == 0) return 0; 
	
	next_position -= next_position / counter; 
	
	counter++; 
	return isLucky(next_position); 
} 

int main() 
{ 
	int x = 50; 
	if( isLucky(x) ) 
		cout << Lucky Number"; 
	else
		cout << Not a Lucky Number"; 
}
