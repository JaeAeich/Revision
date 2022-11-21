#include <bits/stdc++.h>
using namespace std;

/* Kadane's algorithm , Time complexity: O(N), Space Complexity: O(1).

NOTE: There exists another variation of problem where all elements of vectors are negative in that case,
      below algo will fail. In such case return the least greates element of array using lenear search.


*/

int maxSumSubarray(vector<int> &v)
{
    int n = v.size();
    int sum = 0, maxSum = INT_MIN;
    // finding a prefix sum that not negative.
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