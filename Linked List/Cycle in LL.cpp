#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/linked-list-cycle/

Use slow and fast pointers, if cycle exists they will collide else the LL will be exhausted.

TC : O(N)
SC : O(1)
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

// Hare and tortoise method
bool hasCycle(ListNode *head)
{
    // Slow and fast pointers
    ListNode *slow = head;
    ListNode *fast = head;

    // While the LL is exhausted
    while (fast && fast->next)
    {
        // Move the slow at the rate of 1 while fast at 2
        slow = slow->next;
        fast = fast->next->next;

        // If pointers collid that means there exists a cycle
        if (slow == fast)
            return true;
    }

    // If the LL got exhausted, then no cycle found
    return false;
}

// Code By - Jae Aeich