#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include <unordered_map>
#include "tree_node.h"

/**
 * Construct binary tree from preorder and inorder traversal.
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 */
TreeNode* build_tree_preorder_inorder(std::vector<int>& preorder, std::vector<int>& inorder);

/**
 * To find the left and right subtrees, it will look for the root in inorder.
 * Everything on the left should be the left subtree, and everything on the right should be the right subtree.
 * Both subtrees can be constructed by making another recursion call.
 * Always use the next element in preorder to initialize a root.
 */
TreeNode* build_subtree_preorder_inorder(std::vector<int>& preorder, int left, int right, std::unordered_map<int, size_t>& inorder_index_map, int& current_preorder);

/**
 * Construct binary tree from inorder and postorder traversal.
 * Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 */
TreeNode* build_tree_inorder_postorder(std::vector<int>& inorder, std::vector<int>& postorder);

/**
 * To find the left and right subtrees, it will look for the root in inorder.
 * Everything on the left should be the left subtree, and everything on the right should be the right subtree.
 * Both subtrees can be constructed by making another recursion call.
 * Always use the last element in postorder to initialize a root.
 * Partition postorder based on the partition of inorder.
 */
TreeNode* build_subtree_inorder_postorder(std::vector<int>& postorder, int inorder_left, int inorder_right, int postorder_left, int postorder_right, std::unordered_map<int, size_t>& inorder_index_map);

/**
 * Convert Sorted Array to Binary Search Tree
 * Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 * A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 */
TreeNode* convert_sorted_array_to_bst(std::vector<int>& nums);

/**
 * Create the tree node in the BST recursively.
 */
TreeNode* get_bst_node(std::vector<int>& nums, int left, int right);

#endif
