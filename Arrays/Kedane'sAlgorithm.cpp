class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
       int n = nums.size();
       int ans = INT_MIN;   // This variable stores the maximum subarray sum found so far
       int sum = 0;         // This keeps track of the running sum of the current subarray
       int maxi = INT_MIN;  // This will hold the maximum element of the array, to handle the case where all elements are negative
       int start = -1;      // Variable to track the starting index of the maximum subarray
       int end = -1;        // Variable to track the ending index of the maximum subarray

       for (int i = 0; i < n; i++) 
       {
           // Intuition: Kadane's algorithm works by maintaining a running sum of the subarray. If the running sum becomes negative,
           // it won't contribute positively to the maximum sum, so we reset it to zero and start a new subarray from the next index.

           if (sum == 0) start = i;  // If the sum is reset, mark the start of a new potential subarray
           
           maxi = max(maxi, nums[i]);  // Keep track of the largest single element in case all numbers are negative
           
           sum += nums[i];  // Add the current element to the running sum
           
           if (sum < 0) sum = 0;  // If the running sum becomes negative, reset it to 0 (Kadane's step)
           
           // Update the maximum subarray sum and track the ending index
           if (ans < sum) 
           {
               ans = sum;
               end = i;  // Mark the current index as the end of the maximum subarray
           }
       }
       
       // Output the start and end index of the maximum subarray
       cout << "start index is: " << start << endl << "end index is : " << end << endl;
       
       // If the maximum element in the array is negative (i.e., all elements are negative), return that element
       if (maxi < 0) return maxi;
       
       return ans;  // Return the maximum subarray sum
    }
};
