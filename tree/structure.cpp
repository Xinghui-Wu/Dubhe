#include "structure.h"


/**
 * Maximum deepth of binary tree.
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
int get_max_depth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int max_depth = 1;

    std::stack<TreeNode*> tree_node_stack;
    tree_node_stack.push(root);

    std::stack<int> depth_stack;
    depth_stack.push(1);

    TreeNode* current;
    int current_depth;

    // Depth-First Search with Stack
    while (!tree_node_stack.empty())
    {
        current = tree_node_stack.top();
        tree_node_stack.pop();

        current_depth = depth_stack.top();
        depth_stack.pop();

        if (current->right != nullptr)
        {
            tree_node_stack.push(current->right);
            depth_stack.push(current_depth + 1);
        }
        if (current->left != nullptr)
        {
            tree_node_stack.push(current->left);
            depth_stack.push(current_depth + 1);
        }
            
        if (current_depth > max_depth)
        {
            max_depth = current_depth;
        }
    }

    return max_depth;
}


/**
 * Minimum depth of binary tree.
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */
int get_min_depth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    std::queue<TreeNode*> tree_node_queue;
    tree_node_queue.push(root);

    std::queue<int> depth_queue;
    depth_queue.push(1);

    TreeNode* current;
    int current_depth;

    // Breadth-First Search with Queue
    while (!tree_node_queue.empty())
    {
        current = tree_node_queue.front();
        tree_node_queue.pop();

        current_depth = depth_queue.front();
        depth_queue.pop();

        if (current->left == nullptr && current->right == nullptr)
        {
            return current_depth;
        }

        if (current->left != nullptr)
        {
            tree_node_queue.push(current->left);
            depth_queue.push(current_depth + 1);
        }
        if (current->right != nullptr)
        {
            tree_node_queue.push(current->right);
            depth_queue.push(current_depth + 1);
        }
    }

    return 0;
}


/**
 * Validate binary search tree.
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 */
bool is_valid_bst(TreeNode* root)
{
    std::stack<TreeNode*> tree_node_stack;

    TreeNode* current = root;
    TreeNode* prev = nullptr;

    // Use a DFS stack to do the binary tree inorder traversal.
    // The inorder traversal of a BST should be a sorted list.
    // The value of the current visited node should be larger than that of the previous visited node.
    while (current != nullptr || !tree_node_stack.empty())
    {
        while (current != nullptr)
        {
            tree_node_stack.push(current);
            current = current->left;
        }
            
        current = tree_node_stack.top();
        tree_node_stack.pop();

        if (prev != nullptr && current->val <= prev->val)
        {
            return false;
        }
            
        prev = current;
        current = current->right;
    }

    return true;
}


/**
 * Balanced binary tree.
 * Given a binary tree, determine if it is height-balanced.
 * A height-balanced binary tree is defined as: a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 */
bool is_balanced_tree(TreeNode* root)
{
    bool is_balanced = true;

    get_depth(root, is_balanced);

    return is_balanced;
}


/**
 * Compare the depths of the left subtree and right subtree to determine whether the tree is balanced.
 */
int get_depth(TreeNode* root, bool& is_balanced)
{
    // If there already exists an unbalanced subtree, return 0 directly to avoid unnecessary recursion.
    if (!is_balanced || root == nullptr)
    {
        return 0;
    }

    int left_subtree_depth = get_depth(root->left, is_balanced);
    int right_subtree_depth = get_depth(root->right, is_balanced);

    if (abs(left_subtree_depth - right_subtree_depth) > 1)
    {
        is_balanced = false;
    }

    return std::max(left_subtree_depth, right_subtree_depth) + 1;
}


/**
 * Same tree.
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */
bool is_same_tree(TreeNode* p, TreeNode* q)
{
    // Handle the exceptional cases.
    if (p == nullptr && q == nullptr)
    {
        return true;
    }
    if ((p == nullptr) != (q == nullptr))
    {
        return false;
    }
        
    std::queue<TreeNode*> p_tree_node_queue;
    p_tree_node_queue.push(p);

    std::queue<TreeNode*> q_tree_node_queue;
    q_tree_node_queue.push(q);

    TreeNode* p_current;
    TreeNode* q_current;

    // Breadth-First Search with Queue
    while (!p_tree_node_queue.empty() && !q_tree_node_queue.empty())
    {
        p_current = p_tree_node_queue.front();
        p_tree_node_queue.pop();
            
        q_current = q_tree_node_queue.front();
        q_tree_node_queue.pop();

        // Check whether the values of the two nodes are the same.
        if (p_current->val != q_current->val)
        {
            return false;
        }

        // Check the left childs of the two nodes.
        if ((p_current->left == nullptr) != (q_current->left == nullptr))
        {
            return false;
        }
        if (p_current->left != nullptr && q_current->left != nullptr)
        {
            p_tree_node_queue.push(p_current->left);
            q_tree_node_queue.push(q_current->left);
        }

        // Check the right childs of the two nodes.
        if ((p_current->right == nullptr) != (q_current->right == nullptr))
        {
            return false;
        }
        if (p_current->right != nullptr && q_current->right != nullptr)
        {
            p_tree_node_queue.push(p_current->right);
            q_tree_node_queue.push(q_current->right);
        }
    }
        
    return true;
}
