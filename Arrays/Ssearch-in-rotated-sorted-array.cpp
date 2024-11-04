class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        // Approach:
        // 1. We will use a binary search technique to find the target in a rotated sorted array.
        // 2. The main idea is to determine which part of the array (left or right) is sorted at each step.
        // 3. If the left part is sorted, we check if the target lies within that range.
        // 4. If it does, we narrow our search to the left; otherwise, we search the right part.
        // 5. If the right part is sorted, we similarly check if the target lies within that range.
        // 6. If the target is not found, we return -1.

        int n = nums.size(); // Get the size of the input array
        int low = 0;         // Initialize the low pointer to the start of the array
        int high = n - 1;    // Initialize the high pointer to the end of the array

        // While there is still a valid range to search
        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Calculate the mid index

            // Check if the mid element is the target
            if (nums[mid] == target) 
                return mid; // Target found

            // Check if the left part is sorted
            else if (nums[low] <= nums[mid]) 
            {
                // If target is within the sorted left part
                if (target <= nums[mid] && target >= nums[low]) 
                {
                    high = mid - 1; // Search in the left part
                }
                else 
                {
                    low = mid + 1; // Search in the right part
                }
            }
            // The right part is sorted
            else 
            {
                // If target is within the sorted right part
                if (target > nums[mid] && target <= nums[high]) 
                {
                    low = mid + 1; // Search in the right part
                }
                else 
                {
                    high = mid - 1; // Search in the left part
                }
            }
        }
        return -1; // Target not found
    }
};

// Time Complexity:
// The time complexity of this approach is O(log n) in the average and best cases.
// In the worst case, it could degrade to O(n) if the array is heavily rotated.

// Space Complexity:
// The space complexity is O(1) since we are using a constant amount of extra space.
