class Solution {
    private:
    // Helper function to merge two sorted linked lists (A and B) into a single sorted linked list.
    // Creates a dummy node to start and then iterates through A and B, comparing values at each step.
    // At each iteration, appends the node with the smaller value to the result list.
    // Once one list is exhausted, appends the rest of the other list to the result.
    ListNode* merge(ListNode* A, ListNode* B) {
        ListNode* dummy = new ListNode(-1); // Dummy node to act as the start of the merged list
        ListNode* temp = dummy;
        
        // Merge nodes from A and B in sorted order
        while (A && B) {
            if (A->val < B->val) {
                temp->next = A;
                temp = temp->next;
                A = A->next;
            } else {
                temp->next = B;
                temp = temp->next;
                B = B->next;
            }
        }

        // Append remaining nodes from A or B (only one of these while loops will run)
        while (A) {
            temp->next = A;
            temp = temp->next;
            A = A->next;
        }
        while (B) {
            temp->next = B;
            temp = temp->next;
            B = B->next;
        }
        return dummy->next; // Return the head of the merged list, skipping the dummy node
    }

    // Recursive function to merge K sorted linked lists using a divide and conquer approach.
    // Splits the range [start, end] into two halves, recursively merges each half, 
    // and then merges the two halves together.
    ListNode* Partition(int start, int end, vector<ListNode*>& nums) {
        // Base case: if there is only one list in this range, return it
        if (start == end) return nums[start];

        // Find the midpoint to divide the range into two halves
        int mid = start + (end - start) / 2;

        // Recursively partition the left and right halves
        ListNode* A = Partition(start, mid, nums);
        ListNode* B = Partition(mid + 1, end, nums);

        // Merge the two halves and return the result
        return merge(A, B);
    }

public:
    // Main function to merge K sorted linked lists.
    // Initializes the recursive Partition function on the entire list of linked lists.
    ListNode* mergeKLists(vector<ListNode*>& nums) {
        int n = nums.size();
        if (n == 0) return NULL; // If there are no linked lists, return NULL

        return Partition(0, n - 1, nums);
    }
};

/*
    Approach:
    - The function mergeKLists takes a vector of K sorted linked lists and merges them into a single sorted linked list.
    - To achieve this efficiently, it uses a divide and conquer approach:
        1. Partition the list of K linked lists into two halves, and recursively apply the same process to each half.
        2. Once the lists are divided down to individual lists, merge them back together using a helper merge function.
    - The merge function is designed to merge two sorted lists into a single sorted list, keeping the combined list sorted.
    
    Time Complexity:
    - The time complexity of this approach is O(N * log K), where:
      - N is the total number of nodes across all lists.
      - K is the number of lists.
      - This complexity arises because each merge operation involves combining two lists, and there are log K levels of merging in the divide and conquer process.

    Space Complexity:
    - The space complexity is O(log K), which is the space used by the recursion stack for the divide and conquer process.
*/
