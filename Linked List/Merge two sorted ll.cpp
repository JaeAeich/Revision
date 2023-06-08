#include <bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/merge-two-sorted-lists/

Use three pointers to traverse both the lists and attach the smaller node to the current pointer, merging both into one.

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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // Obv cases
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (!l1 && !l2)
        return nullptr;

    // Three pointers
    ListNode *curr = nullptr, *p1 = nullptr, *p2 = nullptr;

    // Setting up pointers so the curr pointer is the least
    if (l1->val <= l2->val)
    {
        curr = l1;
    }
    else
    {
        curr = l2;
    }
    p1 = curr->next;
    p2 = curr == l1 ? l2 : l1;

    // Since curr is least it will be the ans
    ListNode *ans = curr;

    // Till either of the list is exhaused
    while (p1 && p2)
    {

        // Among the two values choose the smaller one
        if (p2->val <= p1->val)
        {
            ListNode *temp = p2;
            p2 = p2->next;
            curr->next = temp;
            curr = temp;
        }
        else
        {
            ListNode *temp = p1;
            p1 = p1->next;
            curr->next = temp;
            curr = temp;
        }
    }

    // If any one of the list is left attach it
    if (p1)
    {
        curr->next = p1;
    }
    else if (p2)
        curr->next = p2;

    return ans;
}

// Code By - Jae Aeich