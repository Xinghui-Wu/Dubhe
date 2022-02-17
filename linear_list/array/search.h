#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

/**
 * Find the element with the target value in a sorted array using binary search.
 */
int binary_search(std::vector<int>& nums, int target);

/**
 * Majority element.
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 */
int get_majority_element(std::vector<int>& nums);

/**
 * Find the duplicate number.
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 */
int find_duplicate(std::vector<int>& nums);

#endif
