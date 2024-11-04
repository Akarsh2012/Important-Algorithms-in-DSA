class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // return head if it is NULL
        // if front is null return curr
        // otherwise do the stuff by taking three dummy nodes to reverse the linked list
        if(head==NULL || head->next==NULL) return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* front=head->next;
        while(front)
        {
            curr->next=prev;
            prev=curr;
            curr=front;
            front=front->next;
        }
        curr->next=prev;
        return curr;
        
    }
};