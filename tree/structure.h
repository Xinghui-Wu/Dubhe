#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "tree_node.h"

/**
 * Maximum deepth of binary tree.
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
int get_max_depth(TreeNode* root);

/**
 * Minimum depth of binary tree.
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */
int get_min_depth(TreeNode* root);

/**
 * Validate binary search tree.
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 */
bool is_valid_bst(TreeNode* root);

/**
 * Balanced binary tree.
 * Given a binary tree, determine if it is height-balanced.
 * A height-balanced binary tree is defined as: a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 */
bool is_balanced_tree(TreeNode* root);

/**
 * Compare the depths of the left subtree and right subtree to determine whether the tree is balanced.
 */
int get_depth(TreeNode* root, bool& is_balanced);

/**
 * Same tree.
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */
bool is_same_tree(TreeNode* p, TreeNode* q);

#endif
