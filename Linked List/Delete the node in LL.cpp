#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : 

Approach 1 : Replace this node with next Node, and delete the next node.

Approach 2 (double pointer): Get the refernce of prev node by using double pointers and change the next pointer 
of prev node to next of next node.

TC : O(1)
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

void deleteNode(ListNode *node)
{
    if (node == nullptr || node->next == nullptr)
    {
        // Handle edge cases where the node or next node is null
        return;
    }
    // Copy the next replace this node with next node
    // Delete the next node
    ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
}

void deleteNode(ListNode* node) {
    ListNode** prev =&node;
    (*prev)=(*prev)->next->next;
}

// Code By - Jae Aeich