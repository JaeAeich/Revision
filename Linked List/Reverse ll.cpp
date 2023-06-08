#include <bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/reverse-linked-list/

Use three pointer prev, curr and next (this will be in loop like temp var, just to to update curr pointer), and
reverse attachments of nodes till none left.

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

ListNode *reverseList(ListNode *head)
{
    // Two pointers current and prev
    ListNode *curr = head, *prev = nullptr;

    while (curr)
    {
        ListNode *next = curr->next;

        // Attach current node to the prev
        curr->next = prev;

        // Current node becomes prev for next iteration
        prev = curr;
        curr = next;
    }

    return prev;
}
// Code By - Jae Aeich