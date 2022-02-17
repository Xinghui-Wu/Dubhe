#include "structure.h"


/**
 * Linked list cycle.
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 */
bool has_cycle(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }
        
    // Traverse the list with two pointers at different speed: a slow pointer and a fast pointer.
    ListNode* slow = head;
    ListNode* fast = head->next;

    // If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
        {
            return false;
        }
            
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}


/**
 * Detect linked list cycle.
 * Given the head of a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 */
ListNode* detect_cycle(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    // Traverse the list with two pointers at different speed: a slow pointer and a fast pointer.
    ListNode* slow = head;
    ListNode* fast = head->next;

    // If there is no cycle in the list, the fast pointer will eventually reach the end and we can return false in this case.
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }
            
        slow = slow->next;
        fast = fast->next->next;
    }

    // l1 is the distance between the head node and the cycle entry node.
    // l2 is the distance between the cycle entry node and the meeting node.
    // c is the length of the cycle.
    // The slow pointer moves l1 + l2 steps, while the fast pointer moves l1 + l2 - 1 + nc steps.
    // 2 (l1 + l2) = l1 + l2 - 1 + nc
    // l1 = nc - 1 - l2 = (n - 1)c + (c - l2) - 1
    // After the slow pointer moves one more step, the head pointer and the slow pointer need the same steps to reach the cycle entry.
    slow = slow->next;

    while (head != slow)
    {
        head = head->next;
        slow = slow->next;
    }
        
    return head;
}


/**
 * Intersection of two linked lists.
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
 * If the two linked lists have no intersection at all, return null.
 */
ListNode* get_intersection_node(ListNode* head_a, ListNode* head_b)
{
    if (head_a == nullptr || head_b == nullptr)
    {
        return nullptr;
    }
        
    // Maintain two pointers initialized at the head of A and B respectively.
    ListNode* current_a = head_a;
    ListNode* current_b = head_b;

    // Let the two pointers both traverse through the lists, one node at a time.
    // When one pointer reaches the end of a list, redirect it to the head of another list.
    // After traversing the two lists twice, the intersection will be found (it can be the tail nullptr).
    while (current_a != current_b)
    {
        if (current_a != nullptr)
        {
            current_a = current_a->next;
        }
        else
        {
            current_a = head_b;
        }

        if (current_b != nullptr)
        {
            current_b = current_b->next;
        }
        else
        {
            current_b = head_a;
        }
    }

    return current_a;
}
