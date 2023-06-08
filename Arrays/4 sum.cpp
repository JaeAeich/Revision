#include <bits/stdc++.h>
using namespace std;
/*
Problem Link : https://leetcode.com/problems/4sum/submissions/

This is extension of 3sum, important point to keep in mind is how to remove duplicate values if they are not
the part of answer and since the constraints on v[i] are high, use long long int .

TC : O(n^3)
SC : O(1)
*/

vector<vector<int>> fourSum(vector<int> &v, int t)
{
    int n = v.size();
    vector<vector<int>> ans = {};

    // Sort to use two-pointer
    sort(begin(v), end(v));

    for (int i = 0; i < n - 3; i++)
    {

        // Remove duplicate value
        if (i && v[i] == v[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {

            // Remove duplicate value
            if (j > i + 1 && v[j] == v[j - 1])
                continue;
            int k = j + 1, l = n - 1;
            while (k < l)
            {

                // Don't use sum = v[i]+v[j]+v[k]+v[l]
                long long int sum = v[i];
                sum += v[j];
                sum += v[k];
                sum += v[l];
                if (sum == t)
                {
                    ans.push_back({v[i], v[j], v[k], v[l]});
                    do
                    {
                        k++;
                    } while (k <= l && v[k] == v[k - 1]);
                    do
                    {
                        l--;
                    } while (k <= l && v[l] == v[l + 1]);
                }
                else if (sum < t)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
}
// Code By - Jae Aeich