#include "construction.h"


/**
 * Construct binary tree from preorder and inorder traversal.
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 */
TreeNode* build_tree_preorder_inorder(std::vector<int>& preorder, std::vector<int>& inorder)
{
    // Build a hashmap to record the relation of value and index for inorder.
    std::unordered_map<int, size_t> inorder_index_map;
    // Keep track of the element that will be used to construct the root.
    int current_preorder = 0;

    for (size_t i = 0; i < inorder.size(); i++)
    {
        inorder_index_map.insert({inorder[i], i});
    }

    TreeNode* root = build_subtree_preorder_inorder(preorder, 0, preorder.size() - 1, inorder_index_map, current_preorder);

    return root;
}


/**
 * To find the left and right subtrees, it will look for the root in inorder.
 * Everything on the left should be the left subtree, and everything on the right should be the right subtree.
 * Both subtrees can be constructed by making another recursion call.
 * Always use the next element in preorder to initialize a root.
 */
TreeNode* build_subtree_preorder_inorder(std::vector<int>& preorder, int left, int right, std::unordered_map<int, size_t>& inorder_index_map, int& current_preorder)
{
    if (left > right)
    {
        return nullptr;
    }
        
    // Select the element indexed by current_preorder as the root.
    TreeNode* root = new TreeNode(preorder[current_preorder++]);

    // Locate the element indexed by current_preorder in inorder list.
    int inorder_index = inorder_index_map[root->val];

    // Recursively build the left and right subtrees.
    root->left = build_subtree_preorder_inorder(preorder, left, inorder_index - 1, inorder_index_map, current_preorder);
    root->right = build_subtree_preorder_inorder(preorder, inorder_index + 1, right, inorder_index_map, current_preorder);

    return root;
}


/**
 * Construct binary tree from inorder and postorder traversal.
 * Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 */
TreeNode* build_tree_inorder_postorder(std::vector<int>& inorder, std::vector<int>& postorder)
{
    // Build a hashmap to record the relation of value and index for inorder.
    std::unordered_map<int, size_t> inorder_index_map;

    for (size_t i = 0; i < inorder.size(); i++)
    {
        inorder_index_map.insert({inorder[i], i});
    }

    TreeNode* root = build_subtree_inorder_postorder(postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inorder_index_map);

    return root;
}


/**
 * To find the left and right subtrees, it will look for the root in inorder.
 * Everything on the left should be the left subtree, and everything on the right should be the right subtree.
 * Both subtrees can be constructed by making another recursion call.
 * Always use the last element in postorder to initialize a root.
 * Partition postorder based on the partition of inorder.
 */
TreeNode* build_subtree_inorder_postorder(std::vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right, std::unordered_map<int, size_t>& inorder_index_map)
{
    if (inorder_left > inorder_right)
    {
        return nullptr;
    }
        
    // Select the element at the end of the postorder list as the root.
    TreeNode* root = new TreeNode(postorder[postorder_right]);

    // Locate the root value in inorder list.
    int inorder_index = inorder_index_map[root->val];
    int num_left = inorder_index - inorder_left;

    // Recursively build the left and right subtrees.
    root->left = build_subtree_inorder_postorder(postorder, inorder_left, inorder_index - 1, postorder_left, postorder_left + num_left - 1, inorder_index_map);
    root->right = build_subtree_inorder_postorder(postorder, inorder_index + 1, inorder_right, postorder_left + num_left, postorder_right - 1, inorder_index_map);

    return root;
}


/**
 * Convert Sorted Array to Binary Search Tree
 * Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 * A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 */
TreeNode* convert_sorted_array_to_bst(std::vector<int>& nums)
{
    TreeNode* root = get_bst_node(nums, 0, nums.size() - 1);

    return root;
}


/**
 * Create the tree node in the BST recursively.
 */
TreeNode* get_bst_node(std::vector<int>& nums, int left, int right)
{
    // Calculate the median index of the array within the specified range.
    int mid = (left + right) / 2;

    // Generate a tree node with the median as its value.
    TreeNode* tree_node = new TreeNode(nums[mid]);

    // Divide and Conquer
    if(left < mid)
    {
        tree_node->left = get_bst_node(nums, left, mid - 1);
    }
    if (mid < right)
    {
        tree_node->right = get_bst_node(nums, mid + 1, right);
    }

    return tree_node;
}
