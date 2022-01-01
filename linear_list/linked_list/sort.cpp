#include "list_node.h"


ListNode* selection_sort(ListNode* head)
{
    ListNode* dummy = new ListNode(-1, head);

    // The last node of the sorted part.
    ListNode* current_i;
    // The predecessor of the first node of the unsorted part.
    ListNode* current_j;

    ListNode* min_node;
    ListNode* temp;

    for (current_i = dummy; current_i->next != nullptr; current_i = min_node)
    {
        min_node = current_i->next;

        for (current_j = current_i->next; current_j->next != nullptr; current_j = current_j->next)
        {
            if (current_j->next->val < min_node->val)
            {
                temp = current_j;
                min_node = temp->next;
            }
        }

        // If the min node is not the first node of the original unsorted part, change its position.
        if (min_node != current_i->next)
        {
            // Remove the min node from its original position.
            temp->next = min_node->next;
            // Insert the min node at the beginning of the unsorted part.
            min_node->next = current_i->next;
            // Insert the min node after the last node of the sorted part.
            current_i->next = min_node;
        }
    }

    return dummy->next;
}


ListNode* merge_sort(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* current = head;

    // Count the number of nodes in the list.
    int length = 0;

    while (current != nullptr)
    {
        length++;
        current = current->next;
    }

    ListNode* dummy = new ListNode(0, head);
    // The head of the first splitted sublist.
    ListNode* left;
    // The head of the second splitted sublist.
    ListNode* right;
    // The tail of the sorted sublist.
    ListNode* tail;

    // Iteratively split the list into sublists of size 1, 2, 4, 8 and so on until the length.
    for (int size = 1; size < length; size <<= 1)
    {
        tail = dummy;
        current = dummy->next;

        while (current != nullptr)
        {
            left = current;
            right = split(left, size);
            current = split(right, size);
            tail = merge(left, right, tail);
        }
    }

    return dummy->next;
}


/**
 * Divide the linked list into two lists.
 * The first list contains first n nodes.
 * Return the head of the second list.
 */
ListNode* split(ListNode* head, int size)
{
    for (int i = 1; i < size && head != nullptr; i++)
    {
        head = head->next;
    }

    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode* second = head->next;
    head->next = nullptr;

    return second;
}


/**
 * Merge two sorted lists.
 * Append the merged sorted linked list to the head node.
 * Return the tail of the merged sorted linked list.
 */
ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head)
{
    ListNode* current = head;

    // Merge the two input sorted linked lists while neither of l1 and l2 is nullptr.
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val <= l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }

        current = current->next;
    }

    // If either l1 or l2 is not nullptr now, connect it to the current pointer.
    if (l1 != nullptr)
    {
        current->next = l1;
    }
    else if (l2 != nullptr)
    {
        current->next = l2;
    }

    // Find the tail pointer.
    while (current->next != nullptr)
    {
        current = current->next;
    }

    return current;
}
