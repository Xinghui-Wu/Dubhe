#include "search.h"


/**
 * Kth smallest element in a BST.
 * Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 */
int get_kth_smallest(TreeNode* root, int k)
{
    std::stack<TreeNode*> tree_node_stack;

    TreeNode* current = root;

    // Use a DFS stack to do the binary tree inorder traversal.
    // The inorder traversal of a BST should be a sorted list.
    while (current != nullptr || !tree_node_stack.empty())
    {
        while (current != nullptr)
        {
            tree_node_stack.push(current);
            current = current->left;
        }
            
        current = tree_node_stack.top();
        tree_node_stack.pop();

        if (k-- == 1)
        {
            return current->val;
        }
            
        current = current->right;
    }

    return 0;
}


/**
 * Lowest common ancestor of a binary tree.
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 */
TreeNode* get_lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // If either p or q is found, return it.
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }

    // Search the left and right subtrees for p and q.
    TreeNode* left = get_lowest_common_ancestor(root->left, p, q);
    TreeNode* right = get_lowest_common_ancestor(root->right, p, q);

    if (left == nullptr)
    {
        return right;
    }
    else if (right == nullptr)
    {
        return left;
    }
    else
    {
        return root;
    }
}


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
void find_path(TreeNode* current, int target_sum, std::vector<std::vector<int>>& path_list, std::vector<int>& path)
{
    // Reach a leaf node.
    if (current->left == nullptr && current->right == nullptr)
    {
        if (target_sum == 0)
        {
            path_list.push_back(path);
        }
            
        return;
    }

    // Recursion and Backtracking.
    if (current->left != nullptr)
    {
        path.push_back(current->left->val);
        find_path(current->left, target_sum - current->left->val, path_list, path);
        path.pop_back();
    }
    if (current->right != nullptr)
    {
        path.push_back(current->right->val);
        find_path(current->right, target_sum - current->right->val, path_list, path);
        path.pop_back();
    }
}


/**
 * Path sum and its amount.
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 */
int count_path_sum(TreeNode* root, int target_sum)
{
    std::unordered_map<long, int> prefix_sum;
    prefix_sum[0] = 1;

    int num_paths = dfs_path_sum(root, prefix_sum, 0, target_sum);

    return num_paths;
}


/**
 * Traverse the binary tree with DFS recursively.
 * Save the prefix sum of the path starting from the root node and ending at the current node.
 * Based on the current and historical prefix sum records, count the number of paths.
 */
int dfs_path_sum(TreeNode* current, std::unordered_map<long, int>& prefix_sum, long current_sum, int target_sum)
{
    if (current == nullptr)
    {
        return 0;
    }

    // Update the prefix sum of the current node.
    current_sum += current->val;

    // Use the difference between curren prefix sum and target sum to count the paths ending at the current node.
    int num_paths = prefix_sum[current_sum - target_sum];

    // Update the hashmap with the current prefix sum.
    prefix_sum[current_sum]++;

    // Search the left and right subtrees.
    num_paths += dfs_path_sum(current->left, prefix_sum, current_sum, target_sum);
    num_paths += dfs_path_sum(current->right, prefix_sum, current_sum, target_sum);
        
    // Backtrack to the parent node.
    prefix_sum[current_sum]--;

    return num_paths;
}
