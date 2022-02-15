#ifndef LIST_NODE_H
#define LIST_NODE_H

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Create a link list and return its head node.
 */
ListNode* create_list(int val_list[], int length);

/**
 * Output the values of the given link list.
 */
void output_list(ListNode* list);

#endif
