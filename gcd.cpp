#include <iostream>
using namespace std;

// Euclid Lemma
int GCD(int x, int y) 
{ 
    if (y == 0) 
        return x; 
    else
        return GCD(y, x % y); 
} 

int main(void) {
    cout << GCD(5, 4) << endl;
    cout << GCD(10, 2) << endl;
    return 0;
}
