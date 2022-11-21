#include<bits/stdc++.h>
using namespace std;
/*
REFERENCE:


Problem Link:https://leetcode.com/problems/maximum-width-ramp/
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. 
The width of such a ramp is j - i.
Given an integer array nums, return the maximum width of a ramp in nums. 
If there is no ramp in nums, return 0.

eg:
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
*/

// //Brute Force Approach ,O(N^2)
// int maxWidthRamp(vector<int>&  v) {
//     int ans=INT_MIN;
//     for(int i=0;i<v.size();i++){
//         for(int j=i+1;j<v.size();j++){
//             if(v[j]>=v[i]){
//                 ans=max(ans,j-i);
//             }
//         }
//     }
//     return ans;
// }


//Optimized approach 
//stack ,O(N)

int maxWidthRamp(vector<int>&  v) {
    
}



int main()
{
    
    return 0;
}
// Code By - Jae Aeich