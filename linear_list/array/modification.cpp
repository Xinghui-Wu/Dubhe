#include "modification.h"


/**
 * Merge sorted array.
 * Given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
 * To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 */
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    // Merge the two sorted arrays with two pointers from the end instead of start, avoiding a temp array.
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] >= nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }

        k--;
    }
        
    // If nums2 still remains some elements, merge them into nums1.
    if (j >= 0)
    {
        for (; k >= 0; k--)
        {
            nums1[k] = nums2[j];
            j--;
        }
    }
}


/**
 * Remove duplicates from sorted array.
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
 * The relative order of the elements should be kept the same.
 * More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
 * Return k after placing the final result in the first k slots of nums.
 */
int remove_duplicates(std::vector<int>& nums)
{
    // Handle the exceptional case.
    if (nums.empty())
    {
        return 0;
    }

    // Maintain the current index k, while k + 1 is the total length.
    int k = 0;

    // Compare each element in the vector with the current one indexed by k.
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[k])
        {
            k++;
            nums[k] = nums[i];
        }
    }

    return k + 1;
}


/**
 * Remove element.
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 * The relative order of the elements may be changed.
 * More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
 * Return k after placing the final result in the first k slots of nums.
 */
int remove_element(std::vector<int>& nums, int val)
{
    // Maintain the current index k, while k + 1 is the total length.
    int k = 0;

    // Compare each element in the vector with val.
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
