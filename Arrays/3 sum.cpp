#include<bits/stdc++.h>
using namespace std;

/*
Extension of 2sum, use extra pointer for third ele, to avoid duplicacy in the answer increament when same elements are found.

TC : O(n^2)
SC : O(n) --> for storing the answer, else O(1)
*/

vector<vector<int>> threeSum(vector<int> &v)
{
    int n = v.size();

    // Vector to store the answer
    vector<vector<int>> ans;

    // Sort to use two-poninter approach
    sort(begin(v), end(v));

    // Till n-2 because after that its impossible to make vec of 3 ele
    for (int i = 0; i < n - 2;)
    {
        int vi = v[i];

        // j and k are two pointers
        for (int j = i + 1, k = n - 1; j < k;)
        {
            int vj = v[j];
            int vk = v[k];
            int sum = vi + vj + vk;

            // If required answer found
            if (sum == 0)
            {
                ans.push_back({vi, vj, vk});

                // Since we can't have duplicate answers, don't consider equal ele
                do
                {
                    j++;
                } while (j <= k && v[j] == vj);
                do
                {
                    k--;
                } while (k >= j && v[k] == vk);
            }
            else if (sum < 0)
                j++;
            else
                k--;
        }

        // To avoid dup, avoid same ele
        do
        {
            i++;
        } while (i < n - 2 && v[i] == vi);
    }
    return ans;
}
// Code By - Jae Aeich