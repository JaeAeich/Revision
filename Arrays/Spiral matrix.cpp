#include<bits/stdc++.h>
using namespace std;

/*
Problem link  : https://leetcode.com/problems/spiral-matrix/

The main thing to focus on this problem is edge case, use four pointers top, right, left, bottom to traverse the matrix
and each time a row or column is exhaused, increment/decrement the corresponding pointer.

TC : O(mn)
SC : O(mn)
*/

vector<int> spiralOrder(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();

    int l = 0, r = m - 1;
    int t = 0, b = n - 1;

    vector<int> ans;

    // Exhaust all the rows and cols, so loop till all the pointer become equal
    while (b >= t && r >= l)
    {
        // Traverse top row
        for (int i = l; i <= r; i++)
        {
            ans.push_back(v[t][i]);
        }
        t++;

        // Traverse right column
        for (int i = t; i <= b; i++)
        {
            ans.push_back(v[i][r]);
        }
        r--;

        if (b >= t)
        {
            // Traverse bottom row
            for (int i = r; i >= l; i--)
            {
                ans.push_back(v[b][i]);
            }
            b--;
        }

        if (l <= r)
        {
            // Traverse left column
            for (int i = b; i >= t; i--)
            {
                ans.push_back(v[i][l]);
            }
            l++;
        }
    }

    return ans;
}

// Code By - Jae Aeich