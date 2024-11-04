#include<iostream> 
#include<bits/stdc++.h>  // Includes all standard headers
using namespace std;
#define ll long long  // Define a shortcut for 'long long' as 'll'

// Function to perform Selection Sort
// Logic: Find the minimum element from the unsorted portion of the array and place it at the front.
// Repeat this process for each position in the array, effectively sorting it.
void SelectionSort(vector<int> &nums)
{
    int n = nums.size();  // Get the size of the array

    // Loop over the array
    for(int i = 0; i < n; i++)
    {
        int min_index = i;  // Assume the first element of the unsorted part is the minimum

        // Find the minimum element in the remaining unsorted part of the array
        for(int j = i; j < n; j++)
        {
            if(nums[j] < nums[min_index])  // Update min_index if a smaller element is found
            {
                min_index = j;
            }
        }

        // Swap the minimum element found with the first unsorted element
        swap(nums[min_index], nums[i]);
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

    // Perform selection sort
    SelectionSort(nums);

    // Print the array after sorting
    cout << "After Sorting: ";
    print(nums);

    return 0;  // End the program
}

/*
Case	      Time Complexity	Space Complexity
Best Case	     O(n^2)	        O(1)
Average Case	 O(n^2)	        O(1)
Worst Case	     O(n^2)	        O(1)
*/