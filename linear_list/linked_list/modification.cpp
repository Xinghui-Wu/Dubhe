#include "modification.h"


/**
 * Merge two sorted lists.
 * Merge two sorted linked lists and return it as a sorted list.
 * The list should be made by splicing together the nodes of the first two lists.
 */
ListNode* merge_two_lists(ListNode* l1, ListNode* l2)
{
    // Create a dummy node (which should be deleted in the end in the actual project).
    ListNode* merged_list = new ListNode();
    // Maintain a current pointer to the merged list.
    ListNode* current = merged_list;

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
    if (l2 != nullptr)
    {
        current->next = l2;
    }

    return merged_list->next;
}


/**
 * Merge k sorted lists.
 * Given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 */
ListNode* merge_k_lists(std::vector<ListNode*>& lists)
{
    if (lists.size() == 0)
    {
        return nullptr;
    }
        
    // Bottom Up Merge Sort
    for (int size = 1; size < lists.size(); size <<= 1)
    {
        for (int i = 0; i < lists.size() - size; i += 2 * size)
        {
            lists[i] = merge_two_lists(lists[i], lists[i + size]);
        }
    }
        
    return lists[0];
}


/**
 * Reverse Linked list.
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 */
ListNode* reverse_list(ListNode* head)
{
    if (head == nullptr)
    {
        return head;
    }

    ListNode* current = head;
    ListNode* next = current->next;
    ListNode* temp;
        
    while (next != nullptr)
    {
        temp = next->next;
        next->next = current;
        current = next;
        next = temp;
    }

    head->next = nullptr;
        
    return current;
}


/**
 * Remove linked list elements.
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has node.val == val, and return the new head.
 */
ListNode* remove_elements(ListNode* head, int val)
{
    ListNode* dummy = new ListNode(0, head);
    ListNode* current = dummy;

    while (current->next != nullptr)
    {
        if (current->next->val == val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
        
    return dummy->next;
}


/**
 * Remove the n-th node from end of list.
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 */
ListNode* remove_nth_from_end(ListNode* head, int n)
{
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Let the fast pointer go first and keep the distance from the slow pointer.
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }
        
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}


/**
 * Remove duplicates from sorted list.
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
 * Return the linked list sorted as well.
 */
ListNode* delete_duplicates(ListNode* head)
{
    ListNode* current = head;

    while (current != nullptr)
    {
        if (current->next != nullptr && current->next->val == current->val)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
        
    return head;
}


/**
 * Remove all duplicates from sorted list.
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * Return the linked list sorted as well.
 */
ListNode* delete_all_duplicates(ListNode* head)
{
    ListNode* dummy = new ListNode(-1000, head);
    ListNode* predecessor = dummy;
    ListNode* current = head;

    while (current != nullptr)
    {
        // if it's a beginning of duplicates sublist, skip all duplicates.
        if (current->next != nullptr && current->val == current->next->val)
        {
            while (current->next != nullptr && current->val == current->next->val)
            {
                current = current->next;
            }

            predecessor->next = current->next;
        }
        // Otherwise, move predecessor.
        else
        {
            predecessor = predecessor->next;
        }
            
        current = current->next;
    }

    return dummy->next;
}
