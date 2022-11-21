#include <bits/stdc++.h>
using namespace std;

/*
Problem Link:https: //leetcode.com/problems/trapping-rain-water/

problem statement: Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Test case:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 In this case, 6 units of rain water (blue section) are being trapped.
*/

class Solution
{
public:
    int trap(vector<int> &v)
    {
        // higher to left and to right .
        vector<int> htl(v.size());
        vector<int> htr(v.size());
        int htn = INT_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            if (htn < v[i])
            {
                htn = v[i];
            }
            htl[i] = htn;
        }
        htn = INT_MIN;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (htn < v[i])
            {
                htn = v[i];
            }
            htr[i] = htn;
        }
        int ans = 0;
        // Rain water will be trapped by ith block if it has a htl and htr.
        for (int i = 0; i < v.size(); i++)
        {
            /*
              amount of water trapped will be the level of water that entire portion will hold.
              i.e min of htl,htr -->this height of water can be stored.
              so this bloc will have total that level of water - its own height.
              */
            ans += min(htl[i], htr[i]) - vs[i];
        }
        return ans;
    }
};

// Code By - Jae Aeich