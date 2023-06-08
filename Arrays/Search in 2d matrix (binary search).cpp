#include<bits/stdc++.h>
using namespace std;

/*
Problem link  : https://leetcode.com/problems/search-a-2d-matrix/

According to the sorting condition we can clearly see that from top rigth corner going down gives a greater ele while going
left gives smaller, this reduces search space like in binary search or BST.

TC : O(mn)
SC : O(1)
*/

bool searchMatrix(vector<vector<int>> &v, int t)
{
    int n = v.size(), m = v[0].size();
    // start itterating from the top right corner.
    for (int i = 0, j = m - 1; i < n && j >= 0;)
    {
        // if ele found return true.
        if (v[i][j] == t)
            return true;
        // if ele is greater move to search space of smaller ele.
        else if (v[i][j] > t)
        {
            j--;
        }
        // move to search space of larger ele.
        else
            i++;
    }
    return false;
}
// Code By - Jae Aeich