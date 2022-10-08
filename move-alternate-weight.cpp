// C++ program to print weights for alternating
// the weighting scale
#include <bits/stdc++.h>
using namespace std;

// DFS method to traverse among states of weighting scales
bool dfs(int residue, int curStep, int wt[], int arr[],
		int N, int steps)
{
	// If we reach to more than required steps,
	// return true
	if (curStep > steps)
		return true;

	// Try all possible weights and choose one which
	// returns 1 afterwards
	for (int i = 0; i < N; i++)
	{
		/* Try this weight only if it is greater than
		current residueand not same as previous chosen
		weight */
		if (arr[i] > residue && arr[i] != wt[curStep - 1])
		{
			// assign this weight to array and recur for
			// next state
			wt[curStep] = arr[i];
			if (dfs(arr[i] - residue, curStep + 1, wt,
					arr, N, steps))
				return true;
		}
	}

	// if any weight is not possible, return false
	return false;
}

// method prints weights for alternating scale and if
// not possible prints 'not possible'
void printWeightsOnScale(int arr[], int N, int steps)
{
	int wt[steps];

	// call dfs with current residue as 0 and current
	// steps as 0
	if (dfs(0, 0, wt, arr, N, steps))
	{
		for (int i = 0; i < steps; i++)
			cout << wt[i] << " ";
		cout << endl;
	}
	else
		cout << "Not possible\n";
}

// Driver code to test above methods
int main()
{
	int arr[] = {2, 3, 5, 6};
	int N = sizeof(arr) / sizeof(int);

	int steps = 10;
	printWeightsOnScale(arr, N, steps);
	return 0;
}
