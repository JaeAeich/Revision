#include <bits/stdc++.h>
using namespace std;

/*
Problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/

Problem statement:Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle in the histogram.

eg:

        Input: heights = [2,1,5,6,2,3]
        Output: 10
        Explanation: The above is a histogram where width of each bar is 1.
        The largest rectangle is shown in the red area, which has an area = 10 units.

explanantion:

for each bar we will find its ple and nle, this will tell us till where the bars are cant be extended.
Once we have the indices of ple and nle we can calculate the width,while the height will the array ele
itself.
*/

// Naive approach ,O(N^2)
int largestRectangleAreaBruteForce(vector<int> &v)
{
    int ans = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int area = 0;
        for (int j = i; j < v.size() && v[j] >= v[i]; j++)
        {
            area += v[i];
        }
        for (int j = i - 1; j >= 0 && v[j] >= v[i]; j--)
        {
            area += v[i];
        }
        ans = max(ans, area);
    }
    return ans;
}

// Stack nle ,ple implementation
// O(N), two pass algorithm
int largestRectangleArea(vector<int> &v)
{
    int n = v.size();
    stack<int> s;
    vector<int> nle(n, -1);
    vector<int> ple(n, -1);
    // looping ele to generate ple and nle
    for (int i = 0; i < v.size(); ++i)
    {
        while (!s.empty() && v[s.top()] >= v[i])
        {
            nle[s.top()] = i;
            s.pop();
        }
        if (!s.empty())
            ple[i] = s.top();
        s.push(i);
    }
    // initiating ans variable to min to find max of all the area.
    int ans = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int n = nle[i];    //-->next idx of lesser ele than ith ele of vector.
        int p = ple[i];    //-->prev idx of lesser ele that ith ele of vector.
        int f = n - p - 1; //-->if the ple and nle exist the width will be n-p-1.

        // likewise diff senario depending on existance on ple and nle..
        if (p == -1 && n != -1)
            f = n;
        else if (p != -1 && n == -1)
            f = v.size() - p - 1;
        else if (n == -1 && p == -1)
            f = v.size(); 

        // finding the max of the areas calculated.
        ans = max(ans, (v[i] * f));
    }
    return ans;
}

// Code By - Jae Aeich