#include <bits/stdc++.h>
using namespace std;

/* Kadane's algorithm , Time complexity: O(N), Space Complexity: O(1).
This algorithm is used to find the maximum contiguous subarray with greates sum in linear time,
e.g: [1,-2,-1,2,-1,2,-1,-4]==>max sum subarray is [2,-1,2] .

Working:
        This algorithm works by simply adding the element till you get a negative sum, once a negative sum is obtained we can be sure this won't 
        previous subarray wont be part of max subarray, in such case we store prev sum and start another subarray from next idx, and if we get
        a sum greater than the previous, we update that. 


NOTE: There exists another variation of problem where all elements of vectors are negative in that case,
      below algo will fail. In such case return the least greatest element of array using lenear search.

      e.g v=[-1,-2,-24,-2,-23,-122] => max sum subarray is [-1].
      This will just be a simple linear search for greatest num.
*/

int maxSumSubarray(vector<int> &v)
{
    int n = v.size();
    int sum = 0, maxSum = INT_MIN;
    // finding a prefix sum thats not negative.
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        maxSum = max(sum, maxSum);
        // If prefix sum ever gets negative, then that array even if extended won't contribute to "Largest sum".
        // If sum becomes negative , set sum to zero and start an new subarray.
        if (sum < 0)
        {
            sum = 0;
            continue;
        }
    }
    return maxSum;
}

// Driver code

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans = maxSumSubarray(v);
    cout << ans;
    return 0;
}
// Code By - Jae Aeich