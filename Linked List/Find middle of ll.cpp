#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/middle-of-the-linked-list/

Use fast and slow ptr till fast is null.

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

ListNode *middleNode(ListNode *head)
{
    // Two pointer, one jumsp one step other two
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// Code By - Jae Aeich