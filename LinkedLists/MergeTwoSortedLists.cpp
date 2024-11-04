class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        // Initialize a dummy node to simplify the process
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // Traverse through both lists
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // Move the tail forward
        }

        // Attach the remaining part of the non-empty list
        if(list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the next of the dummy node (head of the merged list)
        return dummy->next;
    }
};
 // time complexity in the worst case is O(n+m)