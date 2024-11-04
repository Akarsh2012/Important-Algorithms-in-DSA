class Solution {
private:
    int findSize(ListNode* node) {
        int count = 0;
        while (node) {
            count++;
            node = node->next;
        }
        return count;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Find the size of the linked list
        int N = findSize(head);

        // Check for invalid `n` (if n > N, we can't remove the nth node)
        if (n > N) return head;

        // Calculate the position of the node from the start
        int k = N - n + 1;

        // If the first node is to be removed
        if (k == 1) return head->next;

        // Traverse to the (k-1)th node
        ListNode* target = head;
        int count = 1;
        while (count < k - 1) {
            target = target->next;
            count++;
        }

        // Remove the k-th node
        target->next = target->next->next;

        return head;
    }
};


// optimised approach


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node with value 0, and make its next point to the head of the list.
        // This dummy node helps handle edge cases, such as removing the head node,
        // without needing to write extra logic for handling the head pointer.
        ListNode* dummy = new ListNode(0, head);

        // Initialize two pointers, both starting at the dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move the fast pointer `n + 1` steps ahead so that the distance between
        // the fast and slow pointers is `n` nodes.
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both fast and slow pointers until the fast pointer reaches the end.
        // After this loop, the slow pointer will be at the node just before the one
        // that needs to be removed.
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the target node by changing the `next` pointer of the slow node
        // to point to the node after the one that needs to be removed.
        slow->next = slow->next->next;

        // Return the head of the modified list, which is now `dummy->next` since
        // the dummy node is pointing to the original head or the new head if the original was removed.
        return dummy->next;
    }
};
