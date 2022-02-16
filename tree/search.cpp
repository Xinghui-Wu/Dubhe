#include "search.h"


/**
 * Path sum.
 * Given the root of a binary tree and an integer target sum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals target sum.
 */
bool has_path_sum(TreeNode* root, int target_sum)
{
    if (root == nullptr)
    {
        return false;
    }

    std::stack<TreeNode*> tree_node_stack;
    tree_node_stack.push(root);

    std::stack<int> path_sum_stack;
    path_sum_stack.push(root->val);

    TreeNode* current;
    int current_path_sum;

    // Depth-First Search with Stack
    while (!tree_node_stack.empty())
    {
        current = tree_node_stack.top();
        tree_node_stack.pop();

        current_path_sum = path_sum_stack.top();
        path_sum_stack.pop();

        if (current->left == nullptr && current->right == nullptr && current_path_sum == target_sum)
        {
            return true;
        }

        if (current->right != nullptr)
        {
            tree_node_stack.push(current->right);
            path_sum_stack.push(current_path_sum + current->right->val);
        }
        if (current->left != nullptr)
        {
            tree_node_stack.push(current->left);
            path_sum_stack.push(current_path_sum + current->left->val);
        }
    }
        
    return false;
}


/**
 * Path sum and paths.
 * Given the root of a binary tree and an integer target sum, return all root-to-leaf paths where the sum of the node values in the path equals target sum.
 * Each path should be returned as a list of the node values, not node references.
 */
std::vector<std::vector<int>> path_sum(TreeNode* root, int target_sum)
{
    std::vector<std::vector<int>> path_list;
    std::vector<int> path;

    if (root == nullptr)
    {
        return path_list;
    }

    path.push_back(root->val);

    find_path(root, target_sum - root->val, path_list, path);

    return path_list;
}


/**
 * Traverse the binary tree with DFS recursively.
 * Backtrack to the previous status when one path is found.
 */
void find_path(TreeNode* current, int targetSum, std::vector<std::vector<int>>& path_list, std::vector<int>& path)
{
    // Reach a leaf node.
    if (current->left == nullptr && current->right == nullptr)
    {
        if (targetSum == 0)
        {
            path_list.push_back(path);
        }
            
        return;
    }

    // Recursion and Backtracking.
    if (current->left != nullptr)
    {
        path.push_back(current->left->val);
        find_path(current->left, targetSum - current->left->val, path_list, path);
        path.pop_back();
    }
    if (current->right != nullptr)
    {
        path.push_back(current->right->val);
        find_path(current->right, targetSum - current->right->val, path_list, path);
        path.pop_back();
    }
}
