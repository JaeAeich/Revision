#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/find-the-duplicate-number/

Consider the arrray to be LL without the data field, and value of array as the next pointer, if there is a repeating value
then that means, multiple node point to one node, ie lets say v[i]=p and v[j]=p, this means node i and j point to node j.
This converts it into the problem of finding the beginning of cycle in linked list. 

TC : O(n)
SC : O(1)
*/

// Using hare, tortise method.
// Detecting cycle in LL
int findDuplicate(vector<int> &v)
{
    // Slo and fast pointers
    int slo = v[0], fast = v[0];

    // Find the first collision
    do
    {
        slo = v[slo];
        fast = v[v[fast]];
    } while (slo != fast);

    slo = v[0];

    // Find the beginning of cycle
    while (slo != fast)
    {
        slo = v[slo];
        fast = v[fast];
    }
    return slo;
}

// Code By - Jae Aeich