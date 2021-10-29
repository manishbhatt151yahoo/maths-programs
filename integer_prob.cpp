#include <stdio.h>

int main()
{
	int first, second;
	for ( first=1; first<=5; ++first )
		for ( second=1; second<=5; ++second )
			printf ("%d \n", 5*first + second - 5);
	return 0;
}
