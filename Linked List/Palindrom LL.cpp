#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : 

Approach 1 : Reverse the second half of the LL and compare it with first half.

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


bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    // Find the middle of the LL
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = nullptr, *curr = slow;

    // Reverse the LL from the mid
    while (curr)
    {
        ListNode *n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }

    // Iterate from the mid and if values don't match then its not a palindrom
    ListNode *revHead = prev;
    while (revHead)
    {
        if (revHead->val != head->val)
            return false;

        revHead = revHead->next;
        head = head->next;
    }
    return true;
}

// Code By - Jae Aeich