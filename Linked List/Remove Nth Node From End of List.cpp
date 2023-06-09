#include<bits/stdc++.h>
using namespace std;

/*
Priblem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

To delete any node, jump to the node prev it and set its next pointer to next of next, here calc the number of nodes and 
find how many nodes to jump, take care of the edge case where the node to be deleted is the first one.

TC : O(N)
SC : O(n)
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int len = 0;
    ListNode *temp = head;

    // Find the number of nodes in LL
    while (temp)
    {
        len++;
        temp = temp->next;
    }

    // To remove the first node, move the head pointer
    if (n == len)
    {
        return head->next;
    }

    // Else jump to one place before the node needed to be deleted, and delete it
    temp = head;
    for (int i = 1; i < len - n; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
}
// Code By - Jae Aeich