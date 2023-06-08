#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/

Approach 1 : Sort the array and keep f count, if this ele is consecutive of prev, f++ else f=1, just keep in mind that there can be 
duplicate values in array, so we need to skip them. 

TC : O(nlogn)
SC : O(1)

Approach 2 : Put all the ele in a set and iterate through them, if ele - 1 is present then no operation needs to be performed else check
how many ele are in the set which could form consecutive subsequence with this ele.

TC : O(n)
CS : O(n)
*/

// // Using sorting and counting the freq
// int longestConsecutive(vector<int> &v)
// {
//     if (v.size() <= 1)
//         return v.size();
//     sort(begin(v), end(v));
//     int ans = 1;
//     int f = 1;
//     for (int i = 1; i < v.size(); i++)
//     {
//         // If same ele as prev continue
//         if (v[i] == v[i - 1])
//             continue;

//         // If consecutve count the freq
//         if (v[i] - v[i - 1] == 1)
//         {
//             f++;
//             ans = max(ans, f);
//         }

//         // If a non-consecutive ele found, start a new subsequence
//         else
//         {
//             f = 1;
//         }
//     }
//     return ans;
// }

// Using set 
int longestConsecutive(vector<int> &v)
{
    unordered_set<int> s;
    int ans = 0;

    // Push all the value in set
    for (auto val : v)
    {
        s.insert(val);
    }

    for (auto it = begin(s); it != end(s); it++)
    {
        // If there is ele - 1, then no operation
        if (s.find(*it - 1) != s.end())
            continue;

        // There is a possibility for consecutive sequence
        else
        {
            int f = 1;
            int prev = *it;
            // Find how many consecutive ele are present
            while (s.find(prev + 1) != s.end())
            {
                f++;
                prev = prev + 1;
            }
            ans = max(ans, f);
        }
    }
    return ans;
}
// Code By - Jae Aeich