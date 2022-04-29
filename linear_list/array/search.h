#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

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

/**
 * Top k frequent elements.
 * Given an integer array nums and an integer k, return the k most frequent elements.
 */
std::vector<int> find_top_k_frequent_elements(std::vector<int>& nums, int k);

/**
 * Find the median of two sorted arrays.
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 */
double find_median_sorted_arrays(std::vector<int>& nums1, std::vector<int>& nums2);

/**
 * Get intersection of two arrays.
 * Given two integer arrays nums1 and nums2, return an array of their intersection.
 */
std::vector<int> get_intersection(std::vector<int>& nums1, std::vector<int>& nums2);

#endif
