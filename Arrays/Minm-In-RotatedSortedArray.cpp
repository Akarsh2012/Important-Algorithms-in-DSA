class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        // Approach:
        // We are using a modified binary search to find the minimum element in a rotated sorted array.
        // The main idea is to identify the sorted and unsorted parts of the array.
        // If the current range is sorted, we can immediately return the minimum from the sorted part.
        // Otherwise, we adjust our search space accordingly.

        int n = nums.size(); // Get the size of the input array
        int low = 0;         // Initialize the low pointer to the start of the array
        int high = n - 1;    // Initialize the high pointer to the end of the array

        // Initialize the answer to a large value
        int ans = INT_MAX;

        // While there is still a valid range to search
        while (low <= high)
        {
            // If the part we're checking is already sorted (i.e., no rotation),
            // return the minimum from the sorted part
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]); // Update the answer with the minimum found
                break; // Exit the loop since we found the sorted part
            }

            // Calculate the mid index to check the middle element
            int mid = low + (high - low) / 2;

            // If the left part is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]); // Update the answer with the minimum in the left part
                low = mid + 1; // Move the low pointer to eliminate the sorted part
            }
            // If the right part is sorted
            else {
                ans = min(ans, nums[mid]); // Update the answer with the minimum in the right part
                high = mid - 1; // Move the high pointer to eliminate the sorted part
            }
        }

        return ans; // Return the minimum element found
    }
};

// Time Complexity:
// The time complexity of this approach is O(log n) in the average and best cases
// since we are using binary search to eliminate half of the search space in each iteration.
// In the worst case, when the array is not rotated at all, it could become O(n), 
// but this is an edge case. 

// Space Complexity:
// The space complexity is O(1) because we are using a constant amount of extra space
// (only a few variables) for our calculations.
