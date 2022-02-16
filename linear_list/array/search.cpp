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
