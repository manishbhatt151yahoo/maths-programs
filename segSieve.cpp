#include <bits/stdc++.h>
using namespace std;

void segSieve(int n) {
    int limit = floor(sqrt(n))+1;
    vector<int> prime; 
    simpleSieve(limit, prime); 
    
    int low = limit;
    int high = 2*limit;
    
    while (low < n)
    {
        if (high >= n) 
           high = n;
           
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << " ";
                
        low = low + limit;
        high = high + limit;
    }
}

int main()
{
    int n = 100;
    segSieve(n);
    return 0;
}
