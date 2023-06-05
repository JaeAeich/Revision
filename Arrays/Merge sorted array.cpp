#include<bits/stdc++.h>
using namespace std;
/*
Problem Link : https://leetcode.com/problems/merge-sorted-array/

With extra space
TC : O(n+m)
SC : O(m+n)
Use two pointers to iterate through both the array and keep storing the smallest in another array.

Without extra space
TC : O(mlogm+nlogn)
SC : O(1)

Since the both the arrays are already sorted, this means v1.back() is the largest of v1 while v2[0] is smallest,
we can just iterate from back of v1 and front of v2 ans swap the element such that all the smallest ele are in v1,
then just sort both of them and join.
*/

//     // Using extra space
//     void merge(vector<int>& v1, int n, vector<int>& v2, int m) {
//         int i=0,j=0;
//         vector<int> ans = {};
//         v1.resize(n);

//         // Two pointer
//         while(i<n && j<m){
//             if(v1[i]>=v2[j]){
//                 ans.push_back(v2[j]);
//                 j++;
//             }
//             else{
//                 ans.push_back(v1[i]);
//                 i++;
//             }
//         }
//         while(i<n) ans.push_back(v1[i++]);
//         while(j<m) ans.push_back(v2[j++]);

//         v1=ans;
//     }

// Without using extra space
void merge(vector<int> &v1, int n, vector<int> &v2, int m)
{
    /*
    Since both the arrays are sorted, we can put all the smaller to v1
    and then sort both the arrays, this will make sure that they are in
    correct order.
    */
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (v1[i] > v2[j])
            swap(v1[i], v2[j]);
        i--;
        j++;
    }

    // Sorting
    sort(begin(v1), begin(v1) + n);
    sort(begin(v2), end(v2));

    // Rearranging
    i = n, j = 0;
    while (j < m)
    {
        v1[i++] = v2[j++];
    }
}

// Code By - Jae Aeich