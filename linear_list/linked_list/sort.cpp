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
