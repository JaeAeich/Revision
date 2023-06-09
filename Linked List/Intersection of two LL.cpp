#include <bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/intersection-of-two-linked-lists/

Approach 1 : Use Hashing to store the node's pointer of one list and then traverse the other list and check if the node is present in the map.

TC : O(n)
SC : O(n)

Approach 2 : Move ahead the diff of the len of both the LL, no iterate both the LL at same rate and check if the pointers are same.

TC : O(n)
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

// Using Hashing
ListNode *getIntersectionNode(ListNode *l1, ListNode *l2)
{
    map<ListNode *, int> m;
    while (l1 and l2)
    {
        m[l1]++;
        m[l2]++;
        if (m[l1] > 1)
            return l1;
        if (m[l2] > 1)
            return l2;

        l1 = l1->next;
        l2 = l2->next;
    }
    return nullptr;
}

int getLen(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *getIntersectionNode(ListNode *l1, ListNode *l2)
{
    // Get the length of both the LL
    int lenA = getLen(l1), lenB = getLen(l2);

    // Find the diff in len, because if they intersect, it will be after that point.
    int diff = abs(lenA - lenB);

    // Move the longer LL
    if (lenA < lenB)
        swap(l1, l2);

    while (diff--)
    {
        l1 = l1->next;
    }

    // Check if they intersect
    while (l1 and l2)
    {
        if (l1 == l2)
            return l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    return nullptr;
}

// Code By - Jae Aeich