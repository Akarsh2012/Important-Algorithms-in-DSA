

// logic of Insertion sort is that it always takes an element and put it into its right place by comparing and swapping till you are getting an element in the left side of i that is greater than the element at i

#include<iostream> 
#include<bits/stdc++.h>  // Includes all standard headers
using namespace std;
#define ll long long  // Define a shortcut for 'long long' as 'll'

// Function to perform Insertion Sort
// Logic: For each element, place it in its correct position by comparing 
// it with the elements on the left side (already sorted part).
void InsertionSort(vector<int> &nums)
{
    int n = nums.size();  // Get the size of the array

    // Iterate over each element in the array
    for(int i = 0; i < n; i++)
    {
        int j = i;
        
        // Compare and swap elements while the left-side element is larger
        while(j > 0 && nums[j-1] > nums[j])
        {
            swap(nums[j-1], nums[j]);  // Swap the elements
            j--;  // Move one step left
        }
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

    // Perform insertion sort
    InsertionSort(nums);

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