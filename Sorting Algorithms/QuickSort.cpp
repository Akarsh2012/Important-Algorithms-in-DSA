#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Function to partition the array and return the index of the pivot
int pivot(vector<int> & nums, int low, int high)
{
    int i = low;  // i starts from the left (low)
    int j = high; // j starts from the right (high)

    int piv = nums[low];  // Choose the first element as the pivot

    // Continue swapping until i and j cross
    while (i < j)
    {
        // Find the first element greater than or equal to the pivot from the front
        while (nums[i] <= piv && i < high)  
        {
            i++;  // Increment i to move forward
        }
        
        // Find the first element smaller than or equal to the pivot from the back
        while (nums[j] > piv && j > low)  
        {
            j--;  // Decrement j to move backward
        }
        
        // Swap the out-of-place elements found by i and j
        if (i < j) 
            swap(nums[i], nums[j]);
    }

    // Place the pivot in its correct sorted position by swapping it with nums[j]
    swap(nums[low], nums[j]);

    // Return the index where the pivot is now located
    return j;
}

// QuickSort function that recursively sorts the array
void QuickSort(vector<int> & nums, int low, int high)
{
    if (low >= high) return;  // Base case: when the sub-array has one or no element

    // Partition the array and get the pivot index
    int pivot_index = pivot(nums, low, high);

    // Recursively apply QuickSort to the left of the pivot
    QuickSort(nums, low, pivot_index - 1);

    // Recursively apply QuickSort to the right of the pivot
    QuickSort(nums, pivot_index + 1, high);

    return;
}

int main()
{
    int n;
    cin >> n;  // Input the number of elements

    vector<int> nums(n);  // Create a vector to store n elements

    // Input the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Output the array before sorting
    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Call the QuickSort function to sort the array
    QuickSort(nums, 0, n - 1);

    // Output the array after sorting
    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Case	      Time Complexity	Space Complexity
Best Case	     O(n log n)	        O(1)
Average Case	 O(n log n)	        O(1)
Worst Case	     O(n^2)	            O(1)

if recursive stack space is considered then for all cases it takes o(log(n)) space

*/