#ifndef SEARCH_H
#define SEARCH_H

#include <unordered_map>
#include "tree_node.h"

/**
 * Kth smallest element in a BST.
 * Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 */
int get_kth_smallest(TreeNode* root, int k);

/**
 * Lowest common ancestor of a binary tree.
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 */
TreeNode* get_lowest_common_ancestor(TreeNode* root, TreeNode* p, TreeNode* q);

/**
 * Path sum.
 * Given the root of a binary tree and an integer target sum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals target sum.
 */
bool has_path_sum(TreeNode* root, int target_sum);

/**
 * Path sum and paths.
 * Given the root of a binary tree and an integer target sum, return all root-to-leaf paths where the sum of the node values in the path equals target sum.
 * Each path should be returned as a list of the node values, not node references.
 */
std::vector<std::vector<int>> path_sum(TreeNode* root, int target_sum);

/**
 * Traverse the binary tree with DFS recursively.
 * Backtrack to the previous status when one path is found.
 */
void find_path(TreeNode* current, int target_sum, std::vector<std::vector<int>>& path_list, std::vector<int>& path);

/**
 * Path sum and its amount.
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
 */
int count_path_sum(TreeNode* root, int target_sum);

/**
 * Traverse the binary tree with DFS recursively.
 * Save the prefix sum of the path starting from the root node and ending at the current node.
 * Based on the current and historical prefix sum records, count the number of paths.
 */
int dfs_path_sum(TreeNode* current, std::unordered_map<long, int>& prefix_sum, long current_sum, int target_sum);

#endif
