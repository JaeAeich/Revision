#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/rotate-list/

Find the length of the LL and then find the node before the kth node from the end.
Then make the end of the LL point to the head and the node before the kth node point to null.

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

int getLen(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
        return head;

    ListNode *endPtr = head, *beforeK = head;
    int len = getLen(head);

    k %= len;
    if (!k)
        return head;
    int jump = len - k - 1;

    while (jump--)
    {
        beforeK = beforeK->next;
    }
    while (endPtr->next)
    {
        endPtr = endPtr->next;
    }

    ListNode *ans = beforeK->next;

    endPtr->next = head;
    beforeK->next = nullptr;

    return ans;
}
// Code By - Jae Aeich