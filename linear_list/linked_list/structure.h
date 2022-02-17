#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "list_node.h"

/**
 * Linked list cycle.
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 */
bool has_cycle(ListNode* head);

/**
 * Detect linked list cycle.
 * Given the head of a linked list, return the node where the cycle begins.
 * If there is no cycle, return null.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 */
ListNode* detect_cycle(ListNode* head);

/**
 * Intersection of two linked lists.
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
 * If the two linked lists have no intersection at all, return null.
 */
ListNode* get_intersection_node(ListNode* head_a, ListNode* head_b);

#endif
