#include <iostream>
#include <bits/stdc++.h> // Includes standard libraries
using namespace std; 
#define ll long long 

// Function to merge two halves of the array
void Merge(vector<int> &nums, int low, int mid, int high)
{
    // Create a temporary array to hold the merged results
    vector<int> temp(high - low + 1);
    
    // Initialize pointers for the left and right halves
    int i = low; // Pointer for the left half (from low to mid)
    int j = mid + 1; // Pointer for the right half (from mid + 1 to high)
    int k = 0; // Pointer for the temporary array

    // Merge the two halves until we reach the end of one of the halves
    while ((i <= mid && j <= high))
    {
        if (nums[i] <= nums[j]) // Compare elements from both halves
        {
            temp[k++] = nums[i++]; // If left element is smaller, add it to temp
        }
        else
        {
            temp[k++] = nums[j++]; // If right element is smaller, add it to temp
        }
    }

    // Copy any remaining elements from the left half (if any)
    while (i <= mid)
    {
        temp[k++] = nums[i++]; // Add remaining left elements to temp
    }

    // Copy any remaining elements from the right half (if any)
    while (j <= high)
    {
        temp[k++] = nums[j++]; // Add remaining right elements to temp
    }

    // Reset k to 0 to copy the sorted elements back to the original array
    k = 0;

    // Copy the sorted elements from temp back to the original array nums
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[k++]; // Copy from temp to nums
    }
    return ;
}

// Recursive function to perform Merge Sort
void MergeSort(vector<int> &nums, int low, int high)
{
    // Base condition: If low is less than high, we can continue sorting
    if (low < high)
    {
        // Find the middle point to divide the array into two halves
        int mid = low + (high - low) / 2; // Use (low + high) / 2 to prevent overflow

        // Recursively sort the first half
        MergeSort(nums, low, mid);
        // Recursively sort the second half
        MergeSort(nums, mid + 1, high);
        // Merge the two halves after sorting
        Merge(nums, low, mid, high);
    }
    return; // Return to the caller
}

int main()
{
    int n; // Variable to store the number of elements
    cin >> n; // Input the number of elements
    vector<int> nums(n); // Create a vector to hold the elements

    // Input the elements into the nums vector
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Read each element
    }

    // Print the array before sorting
    cout << "Before Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " "; // Output each element
    }
    cout << endl; // New line after printing

    // Call MergeSort on the entire array
    MergeSort(nums, 0, n - 1);

    // Print the array after sorting
    cout << "After Sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " "; // Output each sorted element
    }
    cout << endl; // New line after printing

    return 0; // Return 0 to indicate successful execution
}

/*
Case	      Time Complexity	Space Complexity
Best Case	     O(n log n)	        O(n)
Average Case	 O(n log n)	        O(n)
Worst Case	     O(n log n)	        O(n)
*/