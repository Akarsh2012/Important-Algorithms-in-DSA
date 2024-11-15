// Question:

// 1574. Shortest Subarray to be Removed to Make Array Sorted
// Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

// Return the length of the shortest subarray to remove.

// A subarray is a contiguous subsequence of the array.





class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the rightmost index `j` where the array becomes unsorted
        int j = n - 1;
        while (j > 0 && nums[j - 1] <= nums[j]) {
            j--; // Move `j` left while the sequence is non-decreasing
        }

        // If the entire array is already sorted, return 0 (no subarray needs to be removed)
        if (j == 0) return 0;

        // Initialize the answer with the length of the prefix that can be removed
        int ans = j;

        // Step 2: Traverse the array from the left to find the shortest subarray to remove
        int i = 0;
        while (i < n && (i == 0 || nums[i] >= nums[i - 1])) { // Traverse as long as the left part is sorted

            // Move `j` to the right until the value at `j` is greater than or equal to the value at `i`
            while (j < n && nums[j] < nums[i]) j++;

            // Update the answer to the minimum length of the subarray to remove
            ans = min(ans, j - i - 1);

            i++; // Move to the next element on the left
        }

        // Return the minimum length of the subarray to be removed
        return ans;
    }
};
