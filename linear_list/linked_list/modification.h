#ifndef MODIFICATION_H
#define MODIFICATION_H

#include <vector>
#include "list_node.h"

/**
 * Merge two sorted lists.
 * Merge two sorted linked lists and return it as a sorted list.
 * The list should be made by splicing together the nodes of the first two lists.
 */
ListNode* merge_two_lists(ListNode* l1, ListNode* l2);

/**
 * Merge k sorted lists.
 * Given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 */
ListNode* merge_k_lists(std::vector<ListNode*>& lists);

/**
 * Remove the n-th node from end of list.
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 */
ListNode* remove_nth_from_end(ListNode* head, int n);

/**
 * Remove duplicates from sorted list.
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
 * Return the linked list sorted as well.
 */
ListNode* delete_duplicates(ListNode* head);

/**
 * Remove all duplicates from sorted list.
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * Return the linked list sorted as well.
 */
ListNode* delete_all_duplicates(ListNode* head);

#endif
