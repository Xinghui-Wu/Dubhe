#include "search.h"


/**
 * Find the element with the target value in a sorted array using binary search.
 */
int binary_search(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    
    return -1;
}


/**
 * Majority element.
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 */
int get_majority_element(std::vector<int>& nums)
{
    int majority_element = nums[0];
    int count = 1;

    // Boyer-Moore Voting Algorithm
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (count == 0)
        {
            majority_element = nums[i];
            count = 1;
        }
        else if (nums[i] == majority_element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
        
    return majority_element;
}


/**
 * Find the duplicate number.
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 */
int find_duplicate(std::vector<int>& nums)
{
    // Floyd's Tortoise and Hare (Cycle Detection)
    int slow = 0;
    int fast = 0;

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
        
    slow = 0;

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
