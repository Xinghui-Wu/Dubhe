#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "tree_node.h"

/**
 * Binary tree inorder traversal.
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 */
std::vector<int> inorder_traversal(TreeNode* root);

/**
 * Binary tree preorder traversal.
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
 */
std::vector<int> preorder_traversal(TreeNode* root);

/**
 * Binary tree postorder traversal.
 * Given the root of a binary tree, return the postorder traversal of its nodes' values.
 */
std::vector<int> postorder_traversal(TreeNode* root);

/**
 * Binary tree level order traversal.
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 */
std::vector<std::vector<int>> level_order_traversal(TreeNode* root);

#endif
