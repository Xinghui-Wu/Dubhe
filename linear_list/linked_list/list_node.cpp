#include <iostream>
#include "list_node.h"


/**
 * Create a link list and return its head node.
 */
ListNode* create_list(int val_list[], int length)
{
    ListNode* head = new ListNode(val_list[0]);
    ListNode* current = head;

    for (size_t i = 1; i < length; i++)
    {
        current->next = new ListNode(val_list[i]);
        current = current->next;
    }

    return head;
}


/**
 * Output the values of the given link list.
 */
void output_list(ListNode* list)
{
    while (list != nullptr)
    {
        std::cout << list->val << std::endl;
        list = list->next;
    }
}
