#define MAX_POINT 3
#define ARR_SIZE 100
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int arr_size);

void printCompositions(int n, int i)
{
	static int arr[ARR_SIZE];
	
	if (n == 0)
	{
		printArray(arr, i);
	}
	else if(n > 0)
	{
		int k;
		for (k = 1; k <= MAX_POINT; k++)
		{
			arr[i]= k;
			printCompositions(n-k, i+1);
		}
	}
}

void printArray(int arr[], int arr_size)
{
	int i;
	for (i = 0; i < arr_size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int n = 5;
	
	cout<<"Different compositions formed by 1, 2 and 3 of "<<n<<" are\n";
	printCompositions(n, 0);
	return 0;
}

