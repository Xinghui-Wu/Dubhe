#ifndef SEARCH_H
#define SEARCH_H

#include "tree_node.h"

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
void find_path(TreeNode* current, int targetSum, std::vector<std::vector<int>>& path_list, std::vector<int>& path);

#endif
