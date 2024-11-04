#include<iostream> 
#include<bits/stdc++.h>  // Includes all standard headers
using namespace std;
#define ll long long  // Define a shortcut for 'long long' as 'll'

// Function to perform Bubble Sort
// Logic: Compare two adjacent elements, if they are not in sorted order, swap them.
// After each full pass, the largest unsorted element moves to its correct position at the end of the array.
void BubbleSort(vector<int> &nums)
{
    int n = nums.size();  // Get the size of the array

    // Outer loop for each pass, starting from the last element and reducing range after each iteration
    for(int i = n-1; i >= 1; i--)
    {
        bool swapped = false;  // Track if a swap happened during this pass

        // Inner loop to compare adjacent elements up to the i-th index
        for(int j = 0; j < i; j++)
        {
            // If current element is greater than the next, swap them
            if(nums[j+1] < nums[j])
            {
                swap(nums[j+1], nums[j]);  // Swap the adjacent elements
                swapped = true;  // Set swapped flag to true
            }
        }

        // If no elements were swapped, array is already sorted; break early
        if(!swapped) break;
    }
    return;  // End the function
}

// Function to print the array
void print(vector<int> &nums)
{
    // Loop through the array and print each element
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;  // Print a new line after printing all elements
    return;
}

int main()
{
    int n;
    cin >> n;  // Input the size of the array

    vector<int> nums(n);  // Declare a vector of size n

    // Input all elements into the array
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Print the array before sorting
    cout << "Before Sorting: ";
    print(nums);

    // Perform bubble sort
    BubbleSort(nums);

    // Print the array after sorting
    cout << "After Sorting: ";
    print(nums);

    return 0;  // End the program
}

/*
Case	      Time Complexity	Space Complexity
Best Case	     O(n)	        O(1)
Average Case	 O(n^2)	        O(1)
Worst Case	     O(n^2)	        O(1)
*/