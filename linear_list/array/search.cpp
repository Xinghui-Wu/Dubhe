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


/**
 * Top k frequent elements.
 * Given an integer array nums and an integer k, return the k most frequent elements.
 */
std::vector<int> find_top_k_frequent_elements(std::vector<int>& nums, int k)
{
    std::vector<int> top_k_frequent_nums(k);

    // Count the occurrences of each number in the vector.
    std::unordered_map<int, int> count_map;

    for (size_t i = 0; i < nums.size(); i++)
    {
        count_map[nums[i]]++;
    }

    // Use priority queue (min heap) to sort the top k frequent numbers.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(&cmp)> frequency_queue(cmp);
        
    for (auto& count: count_map)
    {
        if (frequency_queue.size() < k)
        {
            frequency_queue.emplace(count.first, count.second);
        }
        else if (frequency_queue.top().second < count.second)
        {
            frequency_queue.pop();
            frequency_queue.emplace(count.first, count.second);
        }
    }

    for (int i = k - 1; i >= 0; i--)
    {
        top_k_frequent_nums[i] = frequency_queue.top().first;
        frequency_queue.pop();
    }
        
    return top_k_frequent_nums;
}

bool cmp(std::pair<int, int>& m, std::pair<int, int>& n)
{
    return m.second > n.second;
}


/**
 * Find the median of two sorted arrays.
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 */
double find_median_sorted_arrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    // Make sure that the number of elements in the first vector is not larger than that in the second one.
    if (m > n)
    {
        return find_median_sorted_arrays(nums2, nums1);
    }

    // Divide a set into two subsets equally, while the maximum of the first subset is not larger than the minimum of the second subset.
    // Suppose the first subset has nums1[0] to nums1[i - 1] and nums2[0] to nums2[j - 1] and the second subset has nums1[i] to nums1[m - 1] and nums2[j] to nums2[n - 1].
    // When m + n is even, i + j = m - i + n - j, and when m + n is odd, i + j = m - i + n - j + 1.
    // So we can derive i + j = (m + n + 1) / 2, and use i to represent j that j = (m + n + 1) / 2 - i.
    // We should find i so that nums2[j - 1] <= nums1[i] and nums1[i - 1] <= nums2[j].
    // It is equivalent to find the largest i that nums1[i - 1] <= nums2[j] with binary search.
    int i, j;
    int nums1_i_1, nums1_i, nums2_j_1, nums2_j;

    int left = 0;
    int right = m;

    int left_max;
    int right_min;

    while (left <= right)
    {
        i = (left + right) / 2;
        j = (m + n + 1) / 2 - i;

        nums1_i_1 = (i == 0 ? INT32_MIN : nums1[i - 1]);
        nums1_i = (i == m ? INT32_MAX : nums1[i]);
        nums2_j_1 = (j == 0 ? INT32_MIN : nums2[j - 1]);
        nums2_j = (j == n ? INT32_MAX : nums2[j]);

        if (nums1_i_1 <= nums2_j)
        {
            left_max = std::max(nums1_i_1, nums2_j_1);
            right_min = std::min(nums1_i, nums2_j);

            left = i + 1;
        }
        else
        {
            right = i - 1;
        }
    }
        
    if ((m + n) >> 1 << 1 == (m + n))
    {
        return (double) (left_max + right_min) / 2;
    }
    else
    {
        return (double) left_max;
    }
}


/**
 * Get intersection of two arrays.
 * Given two integer arrays nums1 and nums2, return an array of their intersection.
 */
std::vector<int> get_intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    if (nums1.size() > nums2.size())
    {
        return get_intersection(nums2, nums1);
    }

    std::unordered_set<int> nums_set(nums1.begin(), nums1.end());
    std::unordered_set<int> intersection_set;
        
    for (size_t i = 0; i < nums2.size(); i++)
    {
        if (nums_set.count(nums2[i]) > 0)
        {
            intersection_set.insert(nums2[i]);
        }
    }

    std::vector<int> nums_intersection(intersection_set.begin(), intersection_set.end());

    return nums_intersection;
}
