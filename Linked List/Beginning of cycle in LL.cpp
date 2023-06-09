#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/linked-list-cycle-ii/

Using slow and fast pointer find the first collision of the pointers and then move slow and head at equal rate till collision.

TC : O(n)
SC : 0(1)

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    // Find the first collision
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // If LL got exhausted, no cycle present
    if (!fast or !fast->next)
        return nullptr;

    // Start from the start and move at same rate till collide
    fast = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Code By - Jae Aeich