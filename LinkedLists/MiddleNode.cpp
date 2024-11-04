/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        //if only one node is present return head
        // take two pointers slow and fast 
        // move slow by one step
        // move fast by two step
        // do the process until fast point to null
        // after the processs slow will point to middle element


        if(head->next==NULL) return head;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next!=NULL)
        {
            fast=fast->next->next;
            

            slow =slow->next;
        }
        return slow;
        
    }
};