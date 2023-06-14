#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Using two pointers, one to keep track of the index till where there is no dup and other to traverse the array.

TC : O(n)
SC : 0(1)
*/

int removeDuplicates(vector<int> &v)
{
    int n = v.size();

    // If the len is less that 1 then no dup present
    if (n <= 1)
        return n;

    // Atleast 1 non dup present
    // Also because the loop start from 1 not 0
    int ans = 1;
    int dupSoFar = 0;

    for (int i = 1; i < n; i++)
    {
        // If prev ele is equal to this ele
        // Increase the count of dup
        if (v[i] == v[i - 1])
        {
            dupSoFar++;
        }
        else
        {
            // If dup not present
            // Then move this ele to the index till where there is no dup
            v[i - dupSoFar] = v[i];
            ans++;
        }
    }

    return ans;
}
// Code By - Jae Aeich