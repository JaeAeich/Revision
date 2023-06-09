#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/add-two-numbers/

Keep a carry variable, for every sum of the node, add a new node to the answer LL.

TC : O(N)
SC : O(N)
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // Initialise a carry variable for carry of sum
    int carry = 0;

    // Ans LL
    ListNode *ans = new ListNode();
    ListNode *temp = ans;

    // Iterate till both LL are exhausted
    while (l1 or l2)
    {

        // Extract the value of the node else 0
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;

        // Calculate the total sum, ie sum of the nodes and prev carry
        int totSum = a + b + carry;
        carry = totSum / 10;
        int sum = totSum % 10;

        // Add new node of the ans
        temp->next = new ListNode(sum);
        temp = temp->next;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }

    // If a carry is left, add that to the ans
    if (carry)
    {
        temp->next = new ListNode(carry);
    }
    return ans->next;
}
// Code By - Jae Aeich