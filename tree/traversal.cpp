#include "traversal.h"


/**
 * Binary tree inorder traversal.
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 */
std::vector<int> inorder_traversal(TreeNode* root)
{
    std::vector<int> inorder_val_list;

    std::stack<TreeNode*> tree_node_stack;
    TreeNode* current = root;

    while (current != nullptr || !tree_node_stack.empty())
    {
        while (current != nullptr)
        {
            tree_node_stack.push(current);
            current = current->left;
        }
            
        current = tree_node_stack.top();
        tree_node_stack.pop();

        inorder_val_list.push_back(current->val);
            
        current = current->right;
    }

    return inorder_val_list;
}


/**
 * Binary tree preorder traversal.
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
 */
std::vector<int> preorder_traversal(TreeNode* root)
{
    std::vector<int> preorder_val_list;

    std::stack<TreeNode*> tree_node_stack;
    TreeNode* current = root;

    while (current != nullptr || !tree_node_stack.empty())
    {
        while (current != nullptr)
        {
            preorder_val_list.push_back(current->val);

            tree_node_stack.push(current);
            current = current->left;
        }
            
        current = tree_node_stack.top();
        tree_node_stack.pop();
            
        current = current->right;
    }

    return preorder_val_list;
}


/**
 * Binary tree postorder traversal.
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
 */
std::vector<int> postorder_traversal(TreeNode* root)
{
    std::vector<int> postorder_val_list;

    std::stack<TreeNode*> tree_node_stack;
    TreeNode* current = root;
    TreeNode* temp = nullptr;

    while (current != nullptr || !tree_node_stack.empty())
    {
        while (current != nullptr)
        {
            tree_node_stack.push(current);
            current = current->left;
        }
            
        current = tree_node_stack.top();

        if (current->right == nullptr || current->right == temp)
        {
            postorder_val_list.push_back(current->val);

            tree_node_stack.pop();
            temp = current;
            current = nullptr;
        }
        else
        {
            current = current->right;
        }
    }

    return postorder_val_list;
}


/**
 * Binary tree level order traversal.
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 */
std::vector<std::vector<int>> level_order_traversal(TreeNode* root)
{
    std::vector<std::vector<int>> level_order_val_list;

    if (root == nullptr)
    {
        return level_order_val_list;
    }
        
    std::queue<TreeNode*> tree_node_queue;
    tree_node_queue.push(root);

    TreeNode* current;
    int num_level_tree_nodes;

    // Breadth-First Search with Queue
    while (!tree_node_queue.empty())
    {
        num_level_tree_nodes = tree_node_queue.size();

        // Expand the current vector when going down to the next level.
        std::vector<int> level_val_list(num_level_tree_nodes);

        // All tree nodes in the current queue are from the same level.
        for (size_t i = 0; i < num_level_tree_nodes; i++)
        {
            current = tree_node_queue.front();
            tree_node_queue.pop();

            level_val_list[i] = current->val;

            if (current->left != nullptr)
            {
                tree_node_queue.push(current->left);
            }
            if (current->right != nullptr)
            {
                tree_node_queue.push(current->right);
            }
        }

        level_order_val_list.push_back(level_val_list);
    }
        
    return level_order_val_list;
}
