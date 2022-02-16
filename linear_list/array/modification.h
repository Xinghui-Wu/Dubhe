#ifndef MODIFICATION_H
#define MODIFICATION_H

#include <vector>

/**
 * Merge sorted array.
 * Given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
 * To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 */
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

/**
 * Remove duplicates from sorted array.
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same.
 * More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
 * Return k after placing the final result in the first k slots of nums.
 */
int remove_duplicates(std::vector<int>& nums);

/**
 * Remove element.
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 * The relative order of the elements may be changed.
 * More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
 * Return k after placing the final result in the first k slots of nums.
 */
int remove_element(std::vector<int>& nums, int val);

#endif
