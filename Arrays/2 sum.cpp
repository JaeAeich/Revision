#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/two-sum/

Approach 1: Hash every value and then find if target-v[i] exists in hashset.
TC : O(n)
SC : O(n)

Approach 2 : Sort the array and use two pointers, move pointers based on value of vi + vj.
TC : O(nlogn)
SC : O(1)
*/

vector<int> twoSum(vector<int> &nums, int t)
{
    vector<pair<int, int>> v;

    // storing the input with idx
    for (int i = 0; i < nums.size(); i++)
        v.push_back({nums[i], i});

    // sorting the input
    sort(begin(v), end(v));
    vector<int> ans = {-1, -1};

    // iterating and finding the target
    for (int i = 0, j = v.size() - 1; i < j;)
    {
        int temp = v[i].first + v[j].first;

        // it found return idx
        if (temp == t)
        {
            ans = {v[i].second, v[j].second};
            break;
        }

        // if sum is greater increase the sum and vice versa
        else if (temp > t)
            j--;
        else
            i++;
    }
    return ans;
}

// Code By - Jae Aeich